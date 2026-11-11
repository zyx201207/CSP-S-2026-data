#include<bits/stdc++.h>
using namespace std;
struct fun{
	int a;
	char c;
}e[200005];
int n;
long long ans,cnt,zji,yji,l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>e[i].a>>e[i].c;
		cnt+=e[i].a;
	}
	cnt=cnt/2;
	l=1;
	r=n;
	while (zji<cnt)
	{
		if (l==r) break; 
		if (e[l].c==e[r].c)
		{
			if (e[l].a<e[r].a)
			{
				zji=zji+e[l].a;
				e[r].a=e[r].a-e[l].a;
				e[l].a=0;
				l++;
				continue;
			}
			else
			{
				zji=zji+e[r].a;
			    e[l].a=e[l].a-e[r].a;
				e[r].a=0;
				r--;
				continue;
			}
		}
		else
		{
			if (e[l].a<e[r].a)
			{
				zji+=e[l].a;
				ans+=e[l].a;
				
				if (zji>cnt)
				ans+=(zji-cnt);
				
				e[r].a=e[r].a-e[l].a;
				e[l].a=0;
				l++;
				continue;
			}
			else
			{
				zji+=e[r].a;
				ans+=e[r].a;
				
				if (zji>cnt)
				ans+=(zji-cnt);
				
				e[l].a=e[l].a-e[r].a;
				e[r].a=0;
				r--;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
