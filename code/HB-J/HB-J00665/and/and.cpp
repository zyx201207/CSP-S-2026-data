#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,m,q[200005][35],book[200005],an[35],ans[35],cc[35];
string a;
bool check(string a)
{
	for (int i=0;i<a.size();i++)
	{
		if (a[i]!='0') return true;
	}
	return false;
}
void work(string a,int num)
{
	string b;
	int cc[35],id=0,carry=0,ccf=0,len;
	while (check(a))
	{
		id=0,carry=0,len=a.size();
		while (id<len)
		{
			int t=carry*10+a[id]-'0';
			if (t%2) carry=1;
			else carry=0;
			b+=t/2+'0';
			id++;
		}
		cc[++ccf]=carry;
		a=b;
		b="";
	}
	for (int i=1;i<=ccf;i++)
	{
		q[num][35-i]=cc[i];
	}
}
void chengfa(int x)
{
	int a[35]={},id,carry;
	a[1]=1;
	while(x)
	{
		x--;
		carry=0,id=1;
		while (id<35)
		{
			int t=carry+a[id]*2;
			if (t>=10) carry=1;
			else carry=0;
			a[id]=t%10;
			id++;
		}
	}
	for (int i=1;i<35;i++)
	{
		cc[i]=a[i];
	}
}
void pl(int a[35])
{
	int carry=0;
	for (int i=1;i<35;i++)
	{
		int t=carry+ans[i]+a[i];
		if (t>=10) carry=1;
		else carry=0;
		ans[i]=t%10;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a;
		work(a,i);
	}
	for (int j=0;j<35;j++)
	{
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			if (q[i][j] && book[i]==0) cnt++;
		}
		if (cnt>=m)
		{
			an[j]=1;
			for (int i=1;i<=n;i++)
			{
				if (q[i][j]==0) book[i]=1;
			}
		}
	}
	for (int i=0;i<35;i++)
	{
		if (an[i]==1)
		{
			chengfa(34-i);
			pl(cc);
		}
	}
	int flag=0;
	for (int i=34;i>=1;i--)
	{
		if (ans[i]) flag=1;
		if (flag) cout << ans[i];
	}
	return 0;
}
