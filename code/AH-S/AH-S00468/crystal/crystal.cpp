#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],s[500005],b[500005],ans=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		s[i]=a[i]-a[i-1];
		b[i]=b[i-1]+s[i];
		ans++;
		for(int j=1;j<=i;j++)
	    {
		    m-=b[j];
		    if(m<=0)
		    {   
				if(s[i+1]==s[i+2])
				{
					cout<<ans+1;
				}
				else cout<<ans;
				return 0;
			}
	    }
	}
}
