#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
long long cnt=0;
int n;
struct s
{
	int a;
	char c;
}e[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i].a>>e[i].c;
	}
	int l=1,r=n;
	while(l<=r)
	{
		if(e[l].c!=e[r].c) 
		{
			if(e[l].a<=e[r].a)
			{
				cnt+=e[l].a;
				e[r].a-=e[l].a;
				l++;
			}
			else
			{
				cnt+=e[r].a;
				e[l].a-=e[r].a;
				r--;
			}
		}
		else
		{
			if(e[l].a<=e[r].a)
			{
				e[r].a-=e[l].a;
				l++;
			}
			else
			{
				e[l].a-=e[r].a;
				r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
