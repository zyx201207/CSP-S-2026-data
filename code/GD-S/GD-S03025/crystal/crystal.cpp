#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,tt,s,ans,a[500005],b[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n-1;i++)
	{
		c[i]=b[i+1]-b[i];
	}
	sort(c+1,c+n);
	if(c[1]==c[n-1])
	{
		cout<<m/c[1];
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		if(s+c[i]<=m)
		{
			s+=c[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
