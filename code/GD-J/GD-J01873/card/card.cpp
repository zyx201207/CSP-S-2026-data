#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,M=3005;
bool vis[M];
int n,m,a[N],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		stack<int>s;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]])vis[a[j]]=1,s.push(a[j]);
			else{
				vis[a[j]]=1;
				while(s.top()!=a[j])vis[s.top()]=0,s.pop();
			}
		}
		for(int j=1;j<=m;j++)if(vis[j])ans[j]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" \n"[i==m];
	return 0;
}
