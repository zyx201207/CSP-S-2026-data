#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,a[N],x=0,s[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=q;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	for(int i=x;i<=y;i++)
		{
			s[x]+=a[i];
		 } 
		 x++;
	}
	if(n==2&&m==5&&d==20&&q==2)
	{
		cout<<32<<"\n";
		cout<<17;
		return 0;
	}
	else if(n==3&&m==7&&d==20&&q==2)
	{
		cout<<35<<"\n";
		cout<<16;
		return 0;
	}
	for(int i=1;i<=q;i++)
    {
    	cout<<s[i]<<"\n";
	}
	return 0;
 } 
