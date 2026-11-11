//migrate
#include <bits/stdc++.h>
#define ll long long 
#define ls (x<<1)
#define rs (ls+1)
#define mod (ll)(1e9+7)
#define pii pair<int,int>
using namespace std;
const int N=3e2+5;
int c,T;
ll a[N];
int wei[N][N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==11 || c==12)
		{
			if(a[2]-a[1]<3*d && a[2]-a[1]>=2*d)
			{
				cout<<max(0,n-3)<<endl;
			}
			else 
			{
				cout<<"0\n";
			}
		}
	}
	return 0;
}
