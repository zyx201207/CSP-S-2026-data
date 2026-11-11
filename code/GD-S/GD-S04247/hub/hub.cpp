#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+16;
int n,k;
vector<int>vec[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	n=(n-1)>>1,k>>=1;
	if(n&1)n--,k--;
	n>>=1,k>>=1;
	cout<<n-k<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T,cc;
	cin>>cc>>T;
	while(T--)solve();
	return 0;
}
