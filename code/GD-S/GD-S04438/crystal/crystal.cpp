#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
long long m,a[500004],b[500004],c[500004];
int check(int x,int y)
{
	int q=0;
	while(y>=0&&x-q>=0){
		q++;
		y-=c[x];
		y+=c[x-q];
	}
	return q;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n>>m;
	for (int i = 1;i <=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1;i< n;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	c[1]=b[1];
	for (int i = 2;i <n;i++)
	{
		c[i]=b[i]+c[i-1];
		ans=max(ans,check(i,m));
	}
	cout << ans;
	return 0;
}
