#include<bits/stdc++.h>
using namespace std; 
const int N=2e5+10,inf=-1e9-10; 
int n,m,g[N],ans[N]; 
queue<int> pq; 
vector<int> uu; 
int main() {
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);  
	cin>>n>>m; 
	vector<int> q(m+1); 
	for(int i=1;i<=n;i++) {
		cin>>g[i]; 
		q[g[i]]++; 
	}
	
	for(int i=1;i<=n;i++) {
		uu.clear(); 
		bool flag=false; 
		for(int j=i;j<=n;j++) {
			flag=false; 
			for(int& c:uu) {
				if(flag) {
					c=NULL; 
				}
				if(g[j]==c) flag=true; 
			}
			if(!flag) uu.push_back(g[i]); 
		}
		for(auto c:uu) {
			ans[c]++; 
		}
	}
	for(int i=m;i>=1;i--) {
		cout<<ans[i]<<" "; 
	}
	return 0; 
}
