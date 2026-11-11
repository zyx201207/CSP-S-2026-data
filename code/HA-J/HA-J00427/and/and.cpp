#include <bits/stdc++.h>
using namespace std;
const int N=200000;
int n,m,t,p,maxp,seli,cnt,ans;
bool a[N+10][40];
vector<int> sel[40];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&t);
		if(t==0)continue;
		p=0;
		while(t)
		{
			if(t%2)a[i][p]=true;
			t/=2,++p;
		}
		if(p>maxp)maxp=p;
	}
	seli=maxp+1;
	for(int i=1;i<=n;++i)sel[seli].push_back(i);
	for(int i=maxp;i>=0;--i)
	{
		cnt=0;
		ans=ans<<1;
		for(int j=0;j<sel[seli].size();++j)
		{
			if(a[sel[seli][j]][i])
			{
				sel[i].push_back(sel[seli][j]);
				++cnt;
			}
		}
		if(cnt>=m)
		{
			++ans;
			seli=i;
		}
	}
	printf("%d",ans);
	return 0;
}
