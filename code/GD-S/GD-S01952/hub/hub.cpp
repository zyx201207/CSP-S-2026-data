#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2*1e6+10;
int n,k,u[maxn],v[maxn];
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++)    cin>>u[i]>>v[i];
	cout<<(n-k)/k;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T=1;
	cin>>c>>T;
	while(T--)    solve();
}
