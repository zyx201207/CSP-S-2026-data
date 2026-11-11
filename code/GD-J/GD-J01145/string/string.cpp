#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],s;
char c[200005];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%s",&a[i],&c[i]);
	}
	for(int i=1,j=n;i<j;)
	{
		if(c[i]!=c[j])
		{
			if(a[i]>a[j])
			{
				s=s+a[j];
				a[i]=a[i]-a[j];
				j--;
			}
			else if(a[i]<a[j])
			{
				s=s+a[i];
				a[j]=a[j]-a[i];
				i++;
			}
			else 
			{
				s=s+a[i];
				a[j]=a[j]-a[i];
				i++;
				j--;
			}
		}
		else
		{
			if(a[i]>a[j])
			{
				a[i]=a[i]-a[j];
				j--;
			}
			else if(a[i]<a[j])
			{
				a[j]=a[j]-a[i];
				i++;
			}
			else 
			{
				a[j]=a[j]-a[i];
				i++;
				j--;
			}
		}
	}
	printf("%lld",s);
	return 0;
}
