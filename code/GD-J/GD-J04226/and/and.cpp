#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool flag[N]={};
int a[N];
int n,m;
int ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1u<<30;i>=1;i>>=1)
	{
		int cnt=0;
		ans<<=1;
		for(int j=1;j<=n;j++)
		{
			if((a[j]&i)&&!flag[j])
				cnt++;
		}
		if(cnt<m)
			continue;
		for(int j=1;j<=n;j++)
		{
			if(!(a[j]&i)&&!flag[j])
				flag[j]=true;
		}
		ans|=1u;
	}
	printf("%d\n",ans);
	return 0;
}

