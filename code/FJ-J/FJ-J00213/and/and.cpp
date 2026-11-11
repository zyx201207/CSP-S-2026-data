#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N];
int main(){
	freopen("and5.in","r",stdin);
	freopen("and_5.out","w",stdout);
	long long n,m,mx=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	mx=0;
	if(m==2)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n)
	{
		mx=a[1]&a[2];
		for(int i=3;i<=n;i++)
		{
			mx=mx&a[i];
		}
		cout<<mx;
	}
	return 0;
}
