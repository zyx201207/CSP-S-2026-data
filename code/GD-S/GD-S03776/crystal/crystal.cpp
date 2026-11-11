#include<bits/stdc++.h>
using namespace std;
int n,ans=0,k=1,b=1,c=1,d=1;
long long m;
struct energy{
	long long en;
	long long ch;
	long long numb;
	long long id;
}a[500001]={};
bool cmp1(energy a,energy b)
{
	return a.numb>b.numb;
}
bool cmp2(energy a,energy b)
{
	if(a.en!=b.en)
	{
		return a.en<b.en;
	}
	else
	{
		return a.id>b.id;
	}
	
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].en;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp2);
	a[n].ch=0;
	for(int i=1;i<n;i++)
	{
		a[i].ch=a[i+1].en-a[i].en;
	}
	while(k<n)
	{
		ans+=a[d].ch*b;
		if(ans<=m&&d<n-1)
		{
			b++;
			d++;
			a[c].numb++;
		}
		else
		{
			ans=0;
			b=1;
			c++;
			k++;
			d=k;
		}
	}
	sort(a+1,a+n+1,cmp1);
	cout<<a[1].numb+1;
	return 0;
}
