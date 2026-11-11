#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[2000005];
char c[2000005];
long long cnt;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n ;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	long long i=1,j=n;
	while(i<j)
	{
		if(a[i]==a[j]&&c[i]==c[j])continue;
		if(a[i]!=a[j]&&c[i]==c[j])
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				j--;
			}
			else
			{
				a[j]-=a[i];
				i++;
			}
			continue;
		}
		if(a[i]==a[j]&&c[i]!=c[j])cnt+=a[i];
		if(a[i]!=a[j]&&c[i]!=c[j])
		{
			cnt+=max(a[i],a[j]);
			a[i+1]=a[i]-a[j];
		}
		i++;
		j--;
	}
	cout<<cnt<<'\n';
	return 0;
}

