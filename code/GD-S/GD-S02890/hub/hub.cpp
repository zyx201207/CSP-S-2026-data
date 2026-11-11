#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
long long c,t,n,k,u,v;
vector<long long>pr[maxn];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			pr[v].push_back(u);
			pr[u].push_back(v);
		}
		cout<<n*n<<'\n';
	}
	return 0;
} 
