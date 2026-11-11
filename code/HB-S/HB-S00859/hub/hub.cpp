//hub
#include <bits/stdc++.h>
#define ll long long 
#define ls (x<<1)
#define rs (ls+1)
#define mod (ll)(1e9+7)
#define pii pair<int,int>
using namespace std;
const int N=1e5+5;
int c,T;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ll n,k,t;
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>t>>t;
		if(k>=n)cout<<"0\n";
		else
		{
			n/=2;
			n-=k;
			n=(n+7)/4;
			cout<<max(1ll,n)<<endl;
		}
	}
	return 0;
}
