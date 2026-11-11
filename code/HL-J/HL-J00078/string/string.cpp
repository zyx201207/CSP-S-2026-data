#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
struct node
{
	long long a;
	char c;
}e[200010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i].a>>e[i].c;
	}
	int l=1,r=n;
	while(1)
	{
		if(l>=r) break;
		if(e[l].a==e[r].a&&e[l].c==e[r].c)
		{
			l++;
			r--;
			continue;
		}
		if(e[l].a==e[r].a&&e[l].c!=e[r].c)
		{
			sum+=e[l].a;
			l++;
			r--;
			continue;
		}
		if(e[l].a!=e[r].a&&e[l].c==e[r].c)
		{
			if(e[l].a>e[r].a)
			{
				e[l].a-=e[r].a;
				r--;
				continue;
			}
			if(e[l].a<e[r].a)
			{
				e[r].a-=e[l].a;
				l++;
				continue;
			}
		}
		if(e[l].a!=e[r].a&&e[l].c!=e[r].c)
		{
			if(e[l].a>e[r].a)
			{
				e[l].a-=e[r].a;
				sum+=e[r].a;
				r--;
				continue;
			}
			if(e[l].a<e[r].a)
			{
				e[r].a-=e[l].a;
				sum+=e[l].a;
				l++;
				continue;
			}
		}
	}
	cout<<sum;
	
	return 0;
}