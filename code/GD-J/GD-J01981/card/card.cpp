#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],vis[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)vis[i]=0;
		int num[n+100],cnt=0;
		for(int j=i;j<=n;++j){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				num[++cnt]=a[j];
			}
			else{
				bool ok=0;
				int x=cnt;
				for(int k=1;k<=x;++k){
					if(ok||num[k]==a[j]){
						num[k]=0;
						vis[num[k]]=0;
						ok=1;
						cnt--;
					}
				}
				num[++cnt]=a[j];
			}
		}
		for(int j=1;j<=cnt;++j){
			ans[num[j]]++;
		} 
	} 
	for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
	return 0;
}
