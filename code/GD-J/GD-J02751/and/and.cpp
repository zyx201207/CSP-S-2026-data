#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define int long long
const int M=2e5+1;
int n,m,a[M];
int ans=-1e18;
bool vis[M]={0};
inline int Max(int a,int b)
{	return a>b?a:b;
}
inline int cmp(int a,int b)
{	return a>b;
}
inline void dfs(int cur,int st)
{	if(st==m)
	{	//cur&=a[st];
		ans=Max(ans,cur);
		return;
	}
	for(int i=st;i<=n;i++)
	{	if(!vis[i])
		{	vis[i]=1;
			dfs(cur&a[i],st+1);
			vis[i]=0;
		}
		if(a[i]<cur)
			break;
	}
}
signed main()
{	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/m;i++)
		vis[i]=1,dfs(a[i],1);
	cout<<ans<<"\n";
	return 0;
}
//4 2
//3 15 12 12

//5 3
//31 3 1 15 7

//好家伙 我要剪枝!!!
//I Love CCF!
//有没有必要用SA呢 过不了啊
//last change: 10:56 ;conut down: 01:00:20
