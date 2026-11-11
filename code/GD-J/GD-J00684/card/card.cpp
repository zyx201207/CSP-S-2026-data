#include<bits/stdc++.h>
using namespace std;
namespace FZT{
typedef long long ll;
const int N=5e5+5;
int n,m,a[N],lst[N],pos[N],tmp[N],ans[N];
bool exi[5005][5005],vis[N];
void Main(){
	cin>>n>>m;
	bool spA=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) spA=0;
		lst[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	if(spA){
		for(int i=n;i>=1;i--){
			if(!vis[a[i]]){
				vis[a[i]]=1;
				ans[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
		return;
	}
	if(m<=2){
		if(m==1){
			cout<<n;
			return;
		}
		ans[a[n]]=n;
		int p=0;
		for(int i=n;i>=1;i--){
			if(a[i]!=a[n]){
				p=i;
				break;
			}
		}
		ans[a[p]]=p;
		for(int i=1;i<=p;i++){
			if(a[i]!=a[p]) ans[a[p]]--;
		}
		cout<<ans[1]<<' '<<ans[2];
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			exi[i][j]=1;
		}
		if(lst[i]){
			for(int j=lst[i]+1;j<i;j++){
				for(int k=1;k<=i;k++){
					if(exi[lst[i]][k]&&exi[i][k]) exi[j][k]=0;
				}
			}
			for(int k=1;k<=i;k++){
				if(exi[i][k]) exi[lst[i]][k]=0;
			}
		}
	}
	for(int i=n;i>=1;i--){
		if(!vis[a[i]]){
			vis[a[i]]=1;
			for(int j=1;j<=i;j++){
				ans[a[i]]+=exi[i][j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	FZT::Main();
	return 0;
}
