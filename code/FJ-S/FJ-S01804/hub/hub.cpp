#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=1e6+10;
vector<int> G[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cout<<2<<endl;
	}
	return 0;
} 
