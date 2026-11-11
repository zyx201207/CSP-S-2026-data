#include<bits/stdc++.h>
using namespace std;
int n,jr[2000010],jl[2000010],fl[2000010],fr[2000010];
long long d,a[2000010],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	scanf("%d%d",&C,&T);
	while(T--)
	{
		scanf("%d%lld",&n,&d);ans=0;
		for(int i=1;i<=n;i++)
			scanf("%lld",a+i);
		for(int l=1,r=1;l<=n;l++)
		{while(r<n&&a[r+1]-a[l]<=d)r++;jr[l]=r;}
		for(int r=n,l=n;r>0;r--)
		{while(l>1&&a[r]-a[l-1]<=d)l--;jl[r]=l;}
		jl[n+1]=n+1;
		for(int i=1;i<=n;i++)
		{
			fl[i]=1;
			if(jl[i]<jl[i+1])
				fl[i]+=jl[i+1]-jl[i]+fl[jl[i]]-1;
		}
		for(int i=n;i>0;i--)
		{
			fr[i]=1;
			if(jr[i]>jr[i-1])
				fr[i]+=jr[i]-jr[i-1]+fr[jr[i]]-1;
		}
		for(int l=1;l<=n;l++)
		{
			if(jr[l]<=l+1)continue;
			if(jr[jr[l-1]]>jr[jr[l]-2]&&jr[jr[l-1]]<=jr[jr[l]-1])
			{
				ans+=jr[jr[l-1]]-jr[jr[l]-2]+1LL*fl[l]*(jr[jr[l]-1]-jr[jr[l-1]]);
				if(jr[jr[l]]==jr[jr[l]-1]&&jr[jr[l]-1]>jr[jr[l]-2])ans+=fr[jr[jr[l]]]-1;
				continue;
			}
			if(jr[jr[l-1]]>jr[jr[l]-1])
			{
				ans+=jr[jr[l]-1]-jr[jr[l]-2];
				if(jr[jr[l]]==jr[jr[l]-1]&&jr[jr[l]-1]>jr[jr[l]-2])ans+=fr[jr[jr[l]]]-1;
				continue;
			}
			ans+=1LL*fl[l]*(jr[jr[l]-1]-jr[jr[l]-2]);
			if(jr[jr[l]]==jr[jr[l]-1]&&jr[jr[l]-1]>jr[jr[l]-2])ans+=1LL*fl[l]*(fr[jr[jr[l]]]-1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//Ex???? Mirage(?)
//15:53 first completed(WA)
//16:55 second completed(WA)
//17:04 third completed(WA)
//17:21 fourth completed(WA)
//18:16 daoye wo cheng l! hhhhhhh
/*hao wu liao a
- - -
 - -
- - -
 - -
- - -
 - -
- - -
 - -
- - -
 - -
- - -
 - -
- - -
*/
