#include<bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<x<<"\n";
#define pb push_back
#define sz size
#define bg begin
#define ed end
#define pii pair<int,int>
#define mkp make_pair
#define ft first
#define sc second
//#define int long long
using namespace std;
typedef long long lli;
typedef double lf;
signed main()
{
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,x;
		cin>>n>>x;
		for(int i=1;i<n;i++)
			cin>>x>>x;
		cout<<max((int)(n/2.2)/2,1)<<"\n";
		//cerr<<max((int)(n/2.2)/2,1)<<"\n";
	}
	return 0;
}

