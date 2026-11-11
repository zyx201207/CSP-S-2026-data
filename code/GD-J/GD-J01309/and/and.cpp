#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
bool v[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),v[i]=1;
	int ans=0;
	for(int s=30;s>=0;s--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)if(v[i]&&(a[i]&(1<<s)))cnt++;
		if(cnt>=m)
		{
			ans+=1<<s;
			for(int i=1;i<=n;i++)if(v[i]&&!(a[i]&(1<<s)))v[i]=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
