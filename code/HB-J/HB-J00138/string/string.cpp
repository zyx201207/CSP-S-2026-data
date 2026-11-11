#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int l=0;
int maxa=0;
struct node
{
	long long a;
	int c;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		scanf("%d %c",&x,&y);
		if(y==c[l])
		{
			a[l]+=x;
			continue;
		}
		l++;
		a[l]=x;
		c[l]=y;
		maxa=max(maxa,x);
	}
	if(l==1) 
	{
		cout<<0;
		return 0;
	}
	if(maxa>500)
	{
		vector<node> r;
		for(int i=1;i<=l;i++)
		{
			r.push_back({a[i],c[i]});
		}
		long long cnt=0;
		for(int i=0;i<=((int)r.size()-1)/2;i++)
		{
			if(r[i].c!=r[r.size()-i-1].c) cnt+=r[i].a;
			else if(r[i].a!=r[r.size()-i-1].a) cnt+=abs(r[i].a-r[r.size()-i-1].a);
		}
		cout<<cnt;
	}
	else
	{
		string r;
		for(int i=1;i<=l;i++)
		{
			r+=string(a[i],c[i]);
		}
		long long cnt=0;
		for(int i=0;i<=((int)r.size()-1)/2;i++)
		{
			if(r[i]!=r[r.size()-i-1]) cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
