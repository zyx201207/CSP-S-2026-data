#include <bits/stdc++.h>
using namespace std;
long long m;
long long d[200005],s[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n;
	int da=1,sh=1;
	cin>>n>>m;
	long long a[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]%2==1)
		{
			d[da]=a[i];
			da++;
		}
		else
		{
			s[sh]=a[i];
			sh++;
		}
	}
	if(n==m)
	{
		long long x=a[1];
		for(int i=2;i<=n;i++)
		{
			x=x&a[i];
		}
		cout<<x;
		return 0;
	}
	da-=1,sh-=1;
	sort(a+1,a+1+n);
	sort(d+1,d+1+da);
	sort(s+1,s+1+sh);
	//-----------------------------
	long long dan=d[da],shu=s[sh],k=m-1;
	da-=1,sh-=1;
	if(sh>=k)
	{
		while (k>0)
		{
			k--;
			shu=shu&s[sh];
			sh--;
		}
	}
	//-----------------------
	k=m-1;
	if(da>=k)
	{
		while(k>0)
		{
			k--;
			dan=dan&d[da];
			da--;
		}	
	}
	//-----------------------------
	long long z=a[n];
	for(int i=n-1;i>=n-m+1;i--)
	{
		z=z&a[i];
	}
 //-------------------------------
	long long b=max(dan,shu);
	cout<<max(b,z);
	return 0;
}
