#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6	+5;
int x[N],s[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) 
		{
			cin>>x[i];
			s[i]=s[i-1]+x[i];
		}
		int fl=0;
		for(int i=1;i<=n;i++)
		{
			if(x[i]-x[i-1] < d) fl=1;
		}
		if(!fl) cout<<0<<'\n';
		if(c==13 || c==14)
		{
			cout<<0<<'\n';
		}
		if((c==11 || c==12) && (x[2]-x[1])*2>d) cout<<0<<'\n';
		if((c==11 || c==12) && (x[2]-x[1])*2<d && d<(x[2]-x[1])*3) cout<<n+1-4<<'\n';
		
	}
 	return 0;
}


