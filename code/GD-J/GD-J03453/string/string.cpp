#include<bits/stdc++.h>
using namespace std;
int n,a[200005],st,ed,minl=1e9+2;
long long ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	st=1,ed=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cin>>c[i];
	}
	while(st<ed)
	{
		minl=min(a[st],a[ed]);
		if(a[st]==a[ed]&&c[st]==c[ed])
		{
			st++;
			ed--;
			continue;
		}
		else if(a[st]!=a[ed]&&c[st]==c[ed])
		{
			a[st]-=minl;
			a[ed]-=minl;
			if(a[st]==0) st++;
			if(a[ed]==0) ed--;
			continue;
		}
		else if(c[st]!=c[ed])
		{
			ans+=minl;
			a[st]-=minl;
			a[ed]-=minl;
			if(a[st]==0) st++;
			if(a[ed]==0) ed--;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
