#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,t,sum,a[35],b[35];
struct node
{
	int js,x;
}c[200005];
bool cmp(node aa,node bb)
{
	if(aa.js!=bb.js)return aa.js>bb.js;
	return aa.x>bb.x;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		c[i].x=t;
		while(t)
		{
			c[i].js++;
			if(t&1)a[c[i].js]++;
			t>>=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		while(a[c[i].js]<=1&&c[i].js>=1)
			c[i].x-=(int)pow(2,c[i].js-1)*a[c[i].js],a[c[i].js]=0,c[i].js--;
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		t=c[i].x;
		int ss=0;
		while(t)
		{
			ss++;
			if(t&1)b[ss]++;
			t>>=1;
		}
	}
	for(int i=1;i<=30;i++)
		if(b[i]==m)sum=sum+(int)pow(2,i-1);
	cout<<sum;
	return 0;
}
