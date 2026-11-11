#include <bits/stdc++.h>
using namespace std;
//container
int n,m;
stack<int> s;
int a[500005];
bool vis[300005];
int ans[300005];
//main
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(vis[a[j]] == 0){
				s.push(a[j]);
				vis[a[j]] = 1;
			}else{
				while(s.top() != a[j]){
					vis[s.top()] = 0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			++ans[s.top()];
			vis[s.top()] = 0;
			s.pop();
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}

