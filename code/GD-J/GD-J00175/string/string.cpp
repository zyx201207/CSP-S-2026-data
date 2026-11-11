#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct zf{
	int shu;
	char c;
};
zf a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string out","w",stdout);
	int n;
	cin>>n;
/*	for(int i=1;i<=n;i++)
	{
		cin>>a[i].shu>>a[i].c;
	}
	int x=1,y=n;
	long long ans=0;
	while(x<y)
	{
		
		ans+=min(a[x].shu,a[y].shu);
		a[y].shu-=ans;
		a[x].shu-=ans;
		if(a[x].shu<=0) 
		{
			x++;
		}
		if(a[y].shu<=0) 
		{
			y--;
		}
	}
cout<<ans;*/ 
//	baoli
	string s;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		while(x--)
		{
			s+=y; 
		}
	}
	long long ans=0;
	int x;int y;
	x=0;
	y=s.size()-1;
	while(x<=y)
	{
		if(s[x]!=s[y])
		{
			ans++;
		}
		x++;y--;
	}
	cout<<ans;
	return 0;
 } 
