#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[212345],sum;
int b[212345][2],d[212345][2];
char c[212345];
void f(int l,int r,int cnt)
{
	if (l>n||r>n)
		return;
	int k=min(b[l][1],d[r][1]);
	if (c[l]!=c[n-r+1])
	{
		sum+=k-cnt;
	}
	if (b[l][1]<d[r][1])
		f(l+1,r,k);
	if (b[l][1]>d[r][1])
		f(l,r+1,k);
	if (b[l][1]==d[r][1])
		f(l+1,r+1,k);
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		b[i][0]=b[i-1][1]+1;
		b[i][1]=b[i][0]+a[i]-1;
	}
	for (int i=1;i<=n;i++)
	{
		d[i][0]=d[i-1][1]+1;
		d[i][1]=d[i][0]+a[n-i+1]-1;
	}
	f(1,1,0);
	cout<<sum/2<<endl;	
	return 0;
}
