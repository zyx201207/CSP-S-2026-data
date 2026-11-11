#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#define psbk push_back
#define mkp make_pair
#define F first
#define S second
int c,T,n,k;
inline void solve(){
	cin>>n>>k;
	cout<<(1ll*n*k)%(int)(1e9+7)<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
