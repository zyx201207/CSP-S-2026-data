#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
stack<int>s; 
int vis[500005];
set<int>st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		st.clear();
		for(int j=i;j<=n;j++){
			if(st.count(a[j])==1){
				while(s.size()){
					if(s.top()==a[j]){
						s.pop();
						st.erase(a[j]);
						break;
					}
					st.erase(s.top());
					s.pop();
				}
			}
			s.push(a[j]);
			st.insert(a[j]);
		}
		while(s.size()){
			vis[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<vis[i]<<' ';
	return 0;
}

