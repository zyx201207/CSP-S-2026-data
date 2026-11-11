#include <iostream>
#include <cstdio>
using namespace std;
long long n,a[200010],ans=0;
char c[200010]; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i]>>c[i];
	long long l=1,r=n,lenl=0,lenr=0;
	while(l<r)
	{
		if (a[l]-lenl<=a[r]-lenr)
		{
			if (c[l]!=c[r])ans+=a[l]-lenl;
			lenr+=(a[l]-lenl),lenl=0;
			l++;
		}
		else
		{
			if (c[l]!=c[r])ans+=a[r]-lenr;
			lenl+=(a[r]-lenr),lenr=0;
			r--;
		}
		if (lenl==a[l])lenl=0,l++;
		if (lenr==a[r])lenr=0,r--;
	}
	cout<<ans;
	return 0;
}
