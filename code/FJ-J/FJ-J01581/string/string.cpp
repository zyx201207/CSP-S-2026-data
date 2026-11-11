#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		s+=a[i];
	}
	s=s/2;
	long long l1=0;
	long long j=n;
	long long ans=0;
	int t=0;
	for(int i=1;i<=n;i++)
	{
		if(l1+a[i]>s)
		{
			a[i]=l1-a[i];
		}
		l1+=a[i];
		if(a[i]==a[j] && c[i]==c[j])
		{
			if(l1>=s) break;
			else continue;
		}
		if(a[i]>a[j])
		{
			if(c[i]!=c[j])
			{
				ans+=a[j];
			}
			j--;
			if(c[i]!=c[j])
			{
				ans+=a[i]-a[j+1];
			}
		}
		else if(a[i]==a[j])
		{
			if(c[i]!=c[j])
			{
				ans+=a[i];
			}
			j--;
		}
		else if(a[i]<a[j])
		{
			if(c[i]!=c[j])
			{
				ans+=a[i];
			}
			a[j]-=a[i];
		}
		t++;
		if(l1>=s) break;
		
	}
	cout<<ans;
	return 0;
}
