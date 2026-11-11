#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5050,M=2e6+50;
ll c,T;
ll n,d;
ll a[M];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>T;
	//memset(sum)
	while(T!=0)
	{
		T--;
		cin>>n>>d;
		if(c==11||c==12||c==0)
		{
			for(ll i=1;i<=n;i++)
			{
				cin>>a[i];
			} 
			ll k=abs(a[2]-a[1]);
			if(d<2*k) 
			{
				cout<<0<<endl;
			}
			else
			{
				long long t=0;
				if((d/k)%2!=0)
				cout<<max(t,n-(d/k+2))<<endl;
				else
				cout<<max(t,n-(d/k+1))<<endl;
                //cout<<max(t,n-((d/k+2)))<<endl;
			}
		}
	}
	return 0;
}
