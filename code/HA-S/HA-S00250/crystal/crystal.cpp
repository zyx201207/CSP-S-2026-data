#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long cha[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	long long n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);long long ma=a[n];
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}cha[1]=0;
	for(int i=1;i<=n;i++)
	{
	    long long ci=0,zhi=0;
		for(int j=i+1;j<=n;j++)
		{
			ci+=cha[j]*(j-i);
			zhi=a[j]*(j-i+1);
			if(ci>m) break;
			if(ci<=m&&zhi>=ma)
			{
				cout<<j-i+1;
				return 0;
			}
		}
	}
	return 0;
}
