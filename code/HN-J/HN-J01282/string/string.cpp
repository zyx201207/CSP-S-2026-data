#include<bits/stdc++.h>
using namespace std;
int n,l,r;
unsigned long long sum,lnum,rnum;
struct node{
	int v;
	char w;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].v>>a[i].w;
	}
	l=1;
	r=n;
	lnum=a[l].v;
	rnum=a[r].v;
	while(l<=r)
	{
		
		if(lnum<rnum)
		{
			if(a[l].w!=a[r].w)
			{
				sum+=lnum;
			}
			rnum-=lnum;
			l++;
			lnum=a[l].v;
		}
		else
		{
			if(a[l].w!=a[r].w)
			{
				sum+=rnum;
			}
			lnum-=rnum;
			r--;
			rnum=a[r].v;
		}
	}
	cout<<sum; 
	return 0;
}
