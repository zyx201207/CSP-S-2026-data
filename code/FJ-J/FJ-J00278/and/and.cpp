#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[35],used=0;
struct node
{
	int ai;
	string s;
}a[200005];
string tostr(int x)
{
	string y="";
	int len=0;
	while(x>0)
	{
		char c=(x%2)+'0';
		x/=2;
		y=y+c;
		len++;
	}
	int num=30-len;
	while(len<30)
	{
		y=y+'0';
		len++;
	}
	return y;
}
bool cmp(node x,node y)
{
	return x.s>y.s;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].ai;
	for(int i=1;i<=n;i++)
	{
		a[i].s=tostr(a[i].ai);
	}
	for(int i=1;i<=n;i++)
	{
		string x=a[i].s;
		for(int j=0;j<30;j++)
		{
			if(x[j]=='1') cnt[j]++;
		}
	}
	for(int i=29;i>=0;i--)
	{
		if(cnt[i]>=m)
		{
			used=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		string x=a[i].s;
		reverse(x.begin(),x.begin()+used+1);
		a[i].s=x;
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1].ai;
	for(int i=2;i<=m;i++)
	{
		ans=ans&a[i].ai;
	}
	cout<<ans;
	return 0;
}
