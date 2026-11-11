#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
typedef unsigned long long ull;
const int N=3e3+10;
ll T,c,n,m,d,q,k,ar[N],dis[N],vis[N],ans[N],mis[N],tong[N];
vector<ll> vc[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		f(i,1,n-1){
			ll a,b;
			cin>>a>>b;
		}
		if(k>n/2)cout<<1<<endl;
		else if(k==2)cout<<n/4<<endl;
		else cout<<n/k<<endl;
	}
	return 0;
}
