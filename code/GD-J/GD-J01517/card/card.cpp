#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
ll n,m,a[N],ans[M],vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<ll>s;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(s.top()!=a[j]){
					vis[s.top()]=max(vis[s.top()]-1,0ll);
					s.pop();
				}
				s.pop();
				s.push(a[j]);
			}else s.push(a[j]),vis[a[j]]++;
		}
		while(s.size()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
