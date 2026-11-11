#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100868],k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r)
	{
		int y=0,x=(l+r)/2;
		for(int i=1;i<=x;i++)
		{
			y=y+a[x]-a[i];
		}
		if(y>m)
		{
			r=x-1;
		}else
		{
			l=x+1;
			k=x;
		}
	}
	cout<<k;
	return 0;
}
