#include <bits/stdc++.h>
using namespace std;
const int max_=5e5+5;
int n,m,a[max_],ans[max_];
bitset<max_>vis;
stack<int>st;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis.reset();
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				st.push(a[j]);
			}else{
				while(st.top()!=a[j]){
					vis[st.top()]=0;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}
