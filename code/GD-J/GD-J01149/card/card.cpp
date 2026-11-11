#include<bits/stdc++.h>
using namespace std;
int n,m,b[500005],ans[300005],f[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	f[0]=1e9;
	for(int i=n;i>=1;i--){
		if(f[b[i]]==0){
			f[b[i]]=i;
			for(int j=f[b[i]]+1;j<=n+1;j=f[b[j]]+1){
				ans[b[j-1]]++;
			}
		}else{
			for(int j=f[b[i]]+1;j<=n+1;j=f[b[j]]+1){
				ans[b[j-1]]++;
			}
		}
	}for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
