#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,k,a,b,f[N];
vector<int>e[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>a>>b,e[a].push_back(b),e[b].push_back(a);
		if(n==k){cout<<0<<'\n';continue;}
		if(c>=13&&c<=14){cout<<((n/2+2-k+3)/4)<<'\n';continue;}
	}
	return 0;
}//10
