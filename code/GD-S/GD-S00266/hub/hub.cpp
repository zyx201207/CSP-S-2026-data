#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;
vector<int> v[N];
int c,t;

int sol(){
	int n,k;cin>>n>>k;
	for(int i = 1; i < n; i++){
		int a,b;cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	return max(1LL,((n+1)>>1) - k);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--)cout<<sol()<<"\n";
	return 0; 
} 
