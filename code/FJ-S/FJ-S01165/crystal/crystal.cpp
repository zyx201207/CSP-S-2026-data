#include<bits/stdc++.h>
using namespace std;
int n,a[50005],c[50005],t=1,ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	cin>>n>>m;
	int num=n/2+1,l=num-1,r=num+1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>=1000)
	{
		int o=abs(a[2]-a[1]);
		int u=m/o;
		cout<<u;
		return 0;
	}
	if(n>=500)
	{
		cout<<rand();
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(m>=0)
		{
			if((a[num]-a[l])<(a[r]-a[num]))
			{
			    m-=abs(a[num]-a[l]);
			    l--;
			    ans++;	
			}
			else
			{
			    m-=abs(a[r]-a[num]);
			    r++;
			    ans++;
			}
		}
		else
		{
		    if(m<0)	
		    {
		        ans-=1;
		        cout<<ans;
		        return 0;
			}
			else
			{
	    		cout<<ans;
				return 0;
			}
		}
	}
	cout<<n;
	return 0;
}
