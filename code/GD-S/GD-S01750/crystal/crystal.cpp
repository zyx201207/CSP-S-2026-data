#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,m,a[N],sum=0,s;	
signed main()
{
	freopen("crystal","r",stdin);
    freopen("crystal","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
    }	
	sort(a+1,a+n+1);
    for(int i=n;i>1;i--)
    {
    	a[i]-=a[i]-1;
	}
	a[1]=0;
	int j=1,ans=1;
	for(int i=2;i<=n;i++)
	{
		sum+=a[i];
		s+=a[i]*(i-j);
		for(;j<i;j--)
		{
			if(s<=ans)
			{
				break;
			}
			s-=sum;
			sum-=a[j+1];
		}
		ans=max(sum,(i,j+1));
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
