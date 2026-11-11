#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[1000005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);

	long long mid;
	long long cnt=0;
	long long n1;
	if(n%2==1){
	mid=a[n/2+1];n1=n/2+1;}
	else {
	mid=a[n/2];n1=n/2;}
	long long c[1000005]={0};
	for(int i=1;i<=n1;i++)
	{
		c[i]=a[i]-mid;
	}
	for(int i=n1;i>=1;i--)
	{
		if(m!=0)
		{
			m-=c[i];
			if(m<0)break;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;

}
