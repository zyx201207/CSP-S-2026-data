#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
const int N=2e6+10;
int c,T,n,d,x[N],f[1005][1005];
signed main()
{
    //freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> T;
    while(T--)
    {
    	cin >> n >> d;
    	
    	for(int i=1;i<=n;i++)
    	{
    		cin >> x[i];
		}
		if(n<=3)
		{
			cout << 0 << endl;
			continue;
		}
		if(11<=c&&c<=12)
		{
			int q=x[2]-x[1];
			if(d<q)
			{
				cout << 0 << endl;
				continue;
			}
			else if(d<q*2)
			{
				cout << 0 << endl;
				continue;
			}
			else
			{
				int r=d/q;
				cout << max(n-r*2+1,0ll)<<endl;
				continue;
			}
		}
		else 
		{
			cout << 0 << endl;
	return 0;
}

