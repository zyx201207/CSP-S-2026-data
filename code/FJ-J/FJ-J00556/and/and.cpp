#include<bits/stdc++.h>
using namespace std;
vector<int> x;
int n,m,a[200005],y[35],ans,s[200005][35],d[35];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x.push_back(i);
		int l=0,dd=a[i];
		while(dd)
		{
			d[l]+=dd%2;
			s[i][l]=dd%2;
			
			dd/=2;
			l++;
		}
	}
	
	for(int i=30;i>=0;i--)
	{
		
		if(d[i]>=m)
		{
			vector<int> z;
			ans+=(1<<i);
			memset(y,0,sizeof(y));
			for(int j=0;j<x.size();j++)
			{
				if(s[x[j]][i])
				{
					z.push_back(x[j]);
					for(int kk=0;kk<=i-1;kk++){
						y[kk]+=s[x[j]][kk];
					}
				}
			}
			for(int k=0;k<=i-1;k++)
			{
				d[k]=y[k];
			}
			x=z;
		}
	}
	cout<<ans;
	return 0;
}
