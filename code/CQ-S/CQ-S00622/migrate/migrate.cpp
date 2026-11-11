#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long c,T,n,d,minn,last,res,st,ans,a[2000010],vis[110];
void dfs(long long k,long long ed,long long sum)
{
	if(sum>minn) return ;
	if(k==ed)
	{
		last=0;
		for(int i=st;i<=ed;i++)
		{
			if(vis[i])
			{
				if(!last)
				{
					last=i;
				}
				else
				{
					if(a[i]-a[last]>d) return ;
					last=i;
				}
			}
		}
		if(sum<minn)
		{
			res=1;minn=sum;
		}
		else if(sum==minn)
		{
			res++;
		}
		return ;
	}
	vis[k]=0;
	dfs(k+1,ed,sum);
	vis[k]=1;
	dfs(k+1,ed,sum+1);
	vis[k]=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>T;
//	if(c<=10)
//	{
		while(T--)
		{
			cin>>n>>d;ans=0;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					memset(vis,0,sizeof vis);
					res=0;st=i;minn=inf;
					vis[i]=1;vis[j]=1;
					dfs(i+1,j,0);
					ans+=(res==2);
				}
			}
			cout<<ans<<'\n';
		}
//	}
	return 0;
}
/*
n^2还不是很好打的样子，拿到这40pts应该就有1=了吧 
思考一些性质：1.能构成双径岛屿对的岛屿差距一定>d，否则直接到达不可能得到两条路径
2.恰好两条路径同时最小是个很苛刻的条件，两条路径经过的点路径不存在两条对应上一条的情况
试试DP，设disi,j为以i为起点，到j的最短路径长度，这是好求的，但是怎么求路径数呢，，，
由于是最小的路径，所以路径一定形似1-3-4 1-2-4这种样式，因为不能存在两条及以上的边被另一边包含的情况
感觉要绕晕了
算了打最暴力的部分分吧，188pts应该是2= 
*/
