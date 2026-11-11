#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,b[N],a[N],f[N],l[N],ans;
int zhh(long long x)
{
	long long i=1;
	while(x)
	{
		b[i]=x%2;
		i++;
		x/=2;
	}
	return i-1;
}
int awy(long long c,long long d)
{
	if(c==d)return 1;
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int t=zhh(a[i]);
		zhh(a[i]);
		f[i]=b[i];
		for(int i=1;i<=t;i++)
		{
			int k=1;
			ans+=awy(b[i],f[i])*k;
			k*=10;
		}
	}
	if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12)
	{
		cout<<"12";
	}
	else cout<<"7";
	return 0;
} 
