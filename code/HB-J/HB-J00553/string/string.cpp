#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,cnt,l,r;
struct node{
	int num,p;
}q[2000005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	l=1,r=t;
	for(int i=1;i<=t;i++)
	{
		int n,k;
		char c;
		scanf("%lld",&n);
		cin>>c;
		k=(int)(c-'a'+1);
		q[i].num=n;
		q[i].p=k;
	}
	while(l<r)
	{
		if(q[l].num>q[r].num)
		{
			if(q[l].p!=q[r].p)
			{
				cnt=cnt+q[r].num;
			}
			q[l].num-=q[r].num;
			r--;
		}
		if(q[l].num<q[r].num)
		{
			if(q[l].p!=q[r].p)
			{
				cnt=cnt+q[l].num;
			}
			q[r].num-=q[l].num;
			l++;
		}
		if(q[l].num==q[r].num)
		{
			if(q[l].p!=q[r].p)
			{
				cnt=cnt+q[r].num;
			}
			r--;
			l++;
		}
	}
	cout<<cnt;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
