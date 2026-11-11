// zhu CCF de shu ju shui rang wo fan xiang gua fen
//T4 2^n n^2 logn 15
//QAQ bie gua le a
//score:100+100+58+15=271
//wo yao qi ji gou!
#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e6+10;
int fst[N],nxt[N*2],to[N*2],cnt;
int dep[N],fa[N][30],l[1010][1010],n,k; 
bool flag[N],flag2[N];
void add(int a,int b)
{
	to[++cnt]=b;
	nxt[cnt]=fst[a];
	fst[a]=cnt;
}
void dfs(int x,int f)
{
	fa[x][0]=f;
	for(int i=1;i<=22;i++)
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	dep[x]=dep[f]+1;
	for(int i=fst[x];i>0;i=nxt[i])
	{
		int k=to[i];
		if(k==f)
		{
			continue;
		}
		dfs(k,x); 
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])
	{
		swap(x,y);
	}
	for(int i=22;i>=0;i--)
	{
		if(dep[fa[x][i]]>=dep[y])
		{
			x=fa[x][i];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(int i=22;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int len(int a,int b)
{
	return dep[a]+dep[b]-2*dep[lca(a,b)];
}
void dffs(int x)
{
	flag2[x]=1;
	for(int i=fst[x];i>0;i=nxt[i])
	{
		int k=to[i];
		if(flag[k]&&!flag2[k])
		{
			dffs(k);
		} 
	}
}
int ans=0;
void dfs2(int x,int num=0)
{
//	cout<<x<<" "<<num<<" "<<k<<endl;
	if(num>k)
	{
		return;
	}
	if(x>n)
	{
//		for(int i=1;i<=n;i++)
//		{
//			cout<<flag[i];
//		}
//		cout<<endl;
		if(num!=k)
		{
//			cout<<":("<<endl;
			return;
		}
		for(int i=1;i<=n;i++)
		{
			flag2[i]=0;
		}
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			if(!flag2[i]&&flag[i])
			{
				dffs(i); 
				tot++;
				if(tot==3)
				{
//					cout<<":|"<<endl;
					return;
				}
			} 
		}
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			int minn=999999999;
			for(int j=1;j<=n;j++)
			{
				if(flag[j])
				{
					minn=min(minn,len(i,j)); 
				} 
			}
			maxn=max(maxn,minn);
		}
//		cout<<":) "<<maxn<<endl;
		ans=min(ans,maxn);
		return;
	}
	flag[x]=0;
	dfs2(x+1,num);
	flag[x]=1;
	dfs2(x+1,num+1);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			fst[i]=0;
		}	
		for(int i=1;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		cnt=0;
		dfs(1,0);
		if(k!=2)
		{
			ans=999999999;
			dfs2(1,0);
			printf("%d\n",ans);
		}else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					l[i][j]=len(i,j);
				}
			}
			int ans=999999999;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					int maxn=0;
					for(int k=1;k<=n;k++)
					{
						maxn=max(maxn,min(l[k][i],l[k][j]));
						if(maxn>=ans)
						{
							break;
						}
					}	
					ans=min(ans,maxn);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;	
}
