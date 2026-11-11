#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}m[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt=0,n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i].a>>m[i].c;
	}
	long long l=1,r=n;
	while(l<=r)
	{
		long long minn=min(m[l].a,m[r].a);
		if(m[l].c!=m[r].c)
		{
			cnt+=minn;
		}
		m[l].a-=minn;
		m[r].a-=minn;
		if(m[l].a<=0)l++;
		if(m[r].a<=0)r--;
	}
	cout<<cnt;
	return 0;
}
