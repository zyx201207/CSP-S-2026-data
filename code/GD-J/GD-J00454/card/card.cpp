#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N];
bool bk[N];
int li[N],tim[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		int x;
		cin>>x;
		a[i]=x;
	}
	for(int i=1;i<=n;i++){
		if(bk[a[i]]==0){
			bk[a[i]]=1;
			li[i]=a[i];
			tim[a[i]]=i;
		}else{
			int x=tim[a[i]];
			for(int j=i-1;j>x;j--){
				bk[li[j]]=0;
				ans[li[j]]+=j-tim[li[j]]+1;
				tim[li[j]]=0;
			}
			ans[a[i]]+=i-x;
			bk[a[i]]=1;
			tim[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(bk[i]!=0){
			ans[i]+=n-tim[i]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
