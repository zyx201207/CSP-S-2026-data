#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],da[N],vis[N];
stack<int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int qs=1;qs<=n;qs++){
		memset(vis,0,sizeof(vis));
		for(int i=qs;i<=n;i++){
			if(vis[a[i]]){
				while(!q.empty()&&q.top()!=a[i]){
					vis[q.top()]=0;
					q.pop();
				}
				if(!q.empty()) q.pop();
				q.push(a[i]);
				vis[a[i]]=1;
			}else{
				q.push(a[i]);
				vis[a[i]]=1;
			}
		}
		for(int i=1;i<=m;i++) if(vis[i]) da[i]++;
	}
	for(int i=1;i<=m;i++) cout<<da[i]<<' ';
	return 0;
}
