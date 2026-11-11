#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,sum,cnt,vmax;
long long a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for(long long i=1,j=1;i<=n&&j<=n;)
	{
		while(sum<=m&&j<=n)
		{
			  sum+=b[j-1]*(j-i+1);
			  j++;
		}
		vmax=max(vmax,j-i);
		while(sum>m)
		{
			  sum-=a[j]-a[i];
			  i++;
		}
	}
	cout<<vmax;
	return 0;
}

