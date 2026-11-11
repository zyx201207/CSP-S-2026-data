#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5*1e5,MAXM=3*1e5;
int n,m,cd[MAXN+5],ans[MAXN+5],vis[MAXM+5];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cd[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> S;
		memset(vis,0,sizeof vis);
		for(int k=i;k<=n;k++){
			if(vis[cd[k]]){
				int fr=S.top();
				while(fr!=cd[k]){
					vis[fr]=0;
					S.pop();
					fr=S.top();
				}
			}
			else{
				S.push(cd[k]);
				vis[cd[k]]=1;
			}
			
		}
		for(int j=1;j<=m;j++){
			ans[j]+=vis[j];
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
