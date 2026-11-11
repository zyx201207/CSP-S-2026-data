#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
int df,t,n,d,a[N],b[N],c[N],x,y,s;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>df>>t;
    while(t>0)
    {
    	cin>>n>>d;
    	for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]<0)
			{
				b[x]=a[i];
				x++;
			}
			if(a[i]>0)
			{
				c[y]=a[i];
				y++;
			}
		}
		if(x>=4)
		{
			s+=x-3;
		}
		else if(y>=4)
		{
			s+=y-3;
		}
		cout<<s<<"\n";
		s=0;
		x=0;
		y=0;
		t--;
	}
	return 0;
 } 
