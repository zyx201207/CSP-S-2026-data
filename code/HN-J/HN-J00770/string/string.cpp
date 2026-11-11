#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[200005],n,h=1,t,m;
	long long s=0;
	char c[200005];
	cin>>n;
	t=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	while(h<t)
	{
		m=min(a[h],a[t]);
		if(c[h]!=c[t])
		{
			s+=m;
		}
		a[h]-=m;
		a[t]-=m;
		if(a[h]==0)
		{
			h++;
		}
		if(a[t]==0)
		{
			t--;
		}
	}
	cout<<s;
	return 0;
}
