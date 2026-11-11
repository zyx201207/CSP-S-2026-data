#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],s,f,mi,ans,z;
bool cmp(int x,int y)
{
	return x-z<y-z;
	
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(abs(a[i]-s)<abs(a[mi]-s))
		{
			mi=i;
		}
	}
	z=a[mi];
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++)
	{
		if(m>=z-a[i])
		{
			ans++;
			m=m-z-a[i];
		}
		else
		{
			cout<<ans;
			break;
		} 
	}
	return 0;
}

