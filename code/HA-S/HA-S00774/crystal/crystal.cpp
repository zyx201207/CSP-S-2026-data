#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
long long a[10000000];
long long f[10000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		f[i]=a[i]-f[i-1];
	}
	sort(f+1,f+n+1);
	for(int i=1;i<=n;i++)
	{
		if(f[i]<0){
			f[i]=0-f[i];
		}
	}
	sort(f+1,f+n+1);
	for(int i=1;i<=n;i++)
	{
		if(m>=f[i]){
			sum++;
			m-=f[i];
		}
		else{
			break;
		}
	}
	cout<<sum;
	return 0;
}
