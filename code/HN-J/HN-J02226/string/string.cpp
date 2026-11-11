#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
struct node
{
	char a;
	long long b;
}c[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> c[i].b >> c[i].a;
	}
	for(int i =1;i<=n;i++)
	{
		long long l = c[i].b;
		for(int j=n;j>=i;j--)
		{
			if(c[j].a!=c[i].a)
			{
			    cnt +=min(c[j].b,l);
			    l-=c[j].b;
		    }
		    if(l<c[j].b) c[j].b-=l;
			else c[j].b=0;
			if(l<=0)break;
		}
	}
	cout << cnt;
	
}
