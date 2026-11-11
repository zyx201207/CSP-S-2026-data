#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
using ll=long long;
ll n,m,max_x=-100000000000000;
ll a[500000+5],x[500000+5];
void wypf(ll asdf)
{
	sort(a+1,a+1+n);
	ll s=0,x=0,num=0;
	while(s<=m&&num<n)
	{
		x+=asdf;
		s+=x;
		num++;
	}
	cout<<min(n,num);
	exit(0);
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool cs=true;
	ll asdf;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2)
		asdf=a[2]-a[1];
		if(i>2)
		{
			if(a[i]-a[i-1]!=asdf)
				cs=false;
		}

	}
	if(cs)
	{
		wypf(asdf);
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)
	{
		x[i]=1;
		int s=m;
		for(int j=i-1;j>0;j--)
		{
			s=s-(a[i]-a[j]);
			if(s<0)
				break;
			x[i]++;	
		}
		max_x=max(x[i],max_x);
	}
	cout<<max_x;
	fclose(stdin);fclose(stdout);
	return 0;
}
