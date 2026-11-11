#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int s[200010];
string E(int d)
{
	string s;
	while (d!=0) 
	{
		int t=d%2;
		if (t==1) s+='1';
		else s+='0';
		d/=2;
	}
	return s;
}
int k(int x,int y)
{
	int t=0;
	string x1=E(x),y1=E(y);
	int x2=x1.size(),y2=y1.size();
	int len=min(x2,y2);
	for (int i=0;i<len;i++)
	{
		if (x1[i]==y1[i]) t+=pow(2,i);
	}
	return t;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for (int i=1;i<=n;i++)
	{
		int maxn=0;
		for (int j=1;j<=n;j++)
		{
			if (s[i]!=s[j]) maxn=max(maxn,k(s[i],s[j]));
		}
		ans=max(maxn,ans);
	}
	cout<<ans<<endl;
	return 0;	
}
