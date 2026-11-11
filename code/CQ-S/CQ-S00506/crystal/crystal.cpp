#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],ans=0;
int cmp(int o)
{
	int sum=0,s=0;
	for(int i=o;i<=n;i++)
	{
		if(sum>=m)
		{
			break;
		}
		if(a[i]<a[o]&&(a[o]-a[i])<=(m-sum))
		{
			sum+=a[o]-a[i];
		}
		s++;
	}
	for(int i=o-1;i>=1;i--)
	{
		if(a[i]==a[o])
		{
			s++;
		}
		else
		{
			break;
		}
	}
	return s;
}
bool cnp(int q,int p)
{
	return q>p;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cnp);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		int p=cmp(mid);
		if(p>ans)
		{
			ans=p;
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	cout<<ans;
	return 0;
}

