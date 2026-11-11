#include<bits/stdc++.h>
using namespace std;
long long a[200020];
char c[200020];
int hwc(long long i,long long j)
{long long ans=0;
if(i>=j)
return 0;
if(c[i]==c[j])
{
if(a[i]==a[j])
	ans+=hwc(i+1,j-1);
	else 
	if(a[i]<a[j])
	{
		a[j]-=a[i];
		ans+=hwc(i+1,j);
	}
	else
	{
		a[i]-=a[j];
		ans+=hwc(i,j-1);
	}
	}
else
	{
	if(a[i]==a[j])
	ans=hwc(i+1,j-1)+a[i];
	else 
	if(a[i]<a[j])
	{
		a[j]-=a[i];
		ans=hwc(i+1,j)+a[i];
	}
	else
	{
		a[i]-=a[j];
		ans=hwc(i,j-1)+a[j];
	}
		
	}
	return ans;
}
int main()
{freopen("string.in ","r",stdin);
freopen("string.out ","w",stdout);
long long ans=0;
	int n;
	cin>>n;
	for(int y=1;y<=n;y++)
	cin>>a[y]>>c[y];
	ans=hwc(1,n);
	cout<<ans;
}
