#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
const long N=210000;
long long n,a[N],leng,ans,num1=0,num2=0,k1=1,k2;char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld %c",&a[i],&c[i]);
		leng+=a[i];
	}
	k1=1;
	k2=n;
	for(long long i=1;i<=leng/2;i++)
	{
		num1++;
		num2++;
		if(c[k1]!=c[k2])
		{
			ans++;
		}
		if(num1==a[k1])
		{
			k1++;
			num1=0;
		}
		if(num2==a[k2])
		{
			k2--;
			num2=0;
		}
	}
	cout<<ans;
	return 0;
}

