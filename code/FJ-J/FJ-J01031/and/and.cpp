#include<bits/stdc++.h>
using namespace std;
int a[200005],c[31],n,m,f;
bool b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int s=1;s<=n;s++)
	{
		cin>>a[s];
		for(int x=a[s],y=0;x;y++,x/=2)c[y]+=(x&1);
	}
	for(int s=30;s>=0;s--)
	{
		if(c[s]>=m)
		{
			for(int d=s;d>=0;d--)
			{
				if(c[d]>=m)
				{
					int h=(1<<d);
					for(int g=1;g<=n;g++)
					{
						if(!b[g])
						{
							if((a[g]&h)!=h)
							{
								b[g]=1;
								for(int y=0;a[g];y++,a[g]/=2)c[y]-=(a[g]&1);
							}						
						}
					}
					f+=h;
				}
			}
			cout<<f;
			return 0;
		}
	}
	cout<<f;
	return 0;
}
