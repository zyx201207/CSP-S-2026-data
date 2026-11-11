#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N];
int ans[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(); cout.tie();
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	deque<int> dq;
	for (int i=1;i<=n;++i){
		memset(vis,0,sizeof vis);
		while (!dq.empty()) dq.pop_front();
		for (int j=i;j<=n;++j){
			if (!vis[a[j]]){
				vis[a[j]]=1;
				dq.push_back(a[j]);
			}
			else
				while (!dq.empty() && dq.back()!=a[j]){
					vis[dq.back()]=0;
					dq.pop_back();
				}
		}
		while (!dq.empty()){
			++ans[dq.front()];
			dq.pop_front();
		}
	}
	for (int i=1;i<=m;++i) cout<<ans[i]<<' ';
	return 0;
}
