#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long sum=0;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1,j=n;i<=j;)
	{
		if(a[i]<a[j])
		{
			if(c[i]!=c[j]) sum+=a[i];
			a[j]-=a[i],i++;
		}
		else if(a[i]>a[j])
		{
			if(c[i]!=c[j]) sum+=a[j];
			a[i]-=a[j],j--;
		}
		else
		{
			if(c[i]!=c[j]) sum+=a[i];
			i++,j--;
		}
	}
	cout<<sum;
	return 0;
}
