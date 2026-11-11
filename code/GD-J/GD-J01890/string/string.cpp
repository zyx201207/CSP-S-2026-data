#include <bits/stdc++.h>
using namespace std;
struct node{
	char c;
	int a;
}b[200005];
int n;
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> b[i].a >> b[i].c;
	}
	int j=0,i=1;
	for(int x=1;x<=n;x++)
	{
		int minn=min(b[i].a,b[n-j].a);
		if(b[i].c!=b[n-j].c)
		{
			cnt+=minn;
		}
		b[i].a-=minn;
		b[n-j].a-=minn;
		if(b[i].a==0) i++;
		if(b[n-j].a==0) j++;
		if(i==n-j) break;
	}
	cout<<cnt;
	return 0;
}
