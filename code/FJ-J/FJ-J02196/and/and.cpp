#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
bool cmp(int x,int y)
{
	return x>y;
}
int andd(int x,int y)
{
	int p,q,s=0;
	for(p=1;pow(2,p)<=x;p++);
	for(q=1;pow(2,q)<=y;q++);
	p--,q--;
	for(int i=max(p,q);i>=0;i--)
	{
		int ipow=pow(2,i);
		if(x>=ipow&&y>=ipow)
		{
			x-=ipow;
			y-=ipow;
			s+=ipow;
		}
		else
		{
			if(x>=ipow) x-=ipow;
			if(y>=ipow) y-=ipow;
		}
	}
	return s;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1) cout<<a[1];
	else if(m==2) cout<<andd(a[1],a[2]);
	else if(andd(andd(a[1],a[2]),a[3])==a[1]) cout<<a[1];
	else if(n<=20)
	{
		int x=a[1];
		for(int i=1;i<=m;i++)
		{
			x=andd(x,a[i]);
		}
		cout<<x;
	}
	return 0;
}
