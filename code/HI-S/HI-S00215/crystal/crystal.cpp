#include<bits/stdc++.h>
using namespace std;
long long a[100000000],b[100000000];
long long n,m,ans;
int kd(int x,int l)
{
	for(int i=1;i<=n;i++)
	{
		b[i]=abs(a[i]-x);
	}
	sort(b+1,b+1+n);
	int k=1;
	ans=0;
	while(l-b[k]>=0)
	{
		l-=b[k];
		ans++;
		k++;
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long maxn=0,p,l;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		l=m; 
		p=kd(a[i],l);
		if(p>maxn) maxn=p;
	}
	cout<<maxn;
	return 0;
}
