#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,x[N],ans,y=1;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	int a=0;
    	string b;
    	cin>>a>>b;
    	x[i]=a;
    	s[i]=b[0];
	}
	int z=0;
	if(n%2==0)
	{
		z=n/2+1;
	}
	else
	{
		z=n;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=s[z])
		{
			if(x[i]>=x[z])
			{
				ans+=x[z];
				x[i]-=x[z];
				x[z]=0;
				z--;
				if(x[i]>0)
				{
					i--;
				}
			}
			else
			{
				ans+=x[i];
				x[i]=0;
				x[z]-=x[i];
			}
		}
		else
		{
			if(x[i]>=x[z])
			{
				x[i]-=x[z];
				x[z]=0;
				z--;
				if(x[i]>0)
				{
					i--;
				}
			}
			else
			{
				x[z]-=x[i];
				x[i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
} 
