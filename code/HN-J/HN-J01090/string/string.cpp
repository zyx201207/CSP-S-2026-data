#include<bits/stdc++.h>
using namespace std;
struct str{
	long long a;
	char c;
}b[200005];
int n,l,r;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>b[i].a>>b[i].c;
	l=1;r=n;
	while(l<r)
	{
		if(b[l].c==b[r].c)
		{
			if(b[l].a>b[r].a)
			{
				b[l].a-=b[r].a;
				r--;
			}
			else if(b[l].a==b[r].a)
			{
				l++;
				r--;
			}
			else
			{
				b[r].a-=b[l].a;
				l++;
			}
		}
		else
		{
			if(b[l].a>b[r].a)
			{
				b[l].a-=b[r].a;
				ans+=b[r].a;
				r--;
			}
			else if(b[l].a==b[r].a)
			{
				ans+=b[r].a;
				l++;
				r--;
			}
			else
			{
				b[r].a-=b[l].a;
				ans+=b[l].a;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}/*
10
1 a
2 b
3 c
4 d
5 e
6 f
7 g
8 h
9 i
10 j*/
