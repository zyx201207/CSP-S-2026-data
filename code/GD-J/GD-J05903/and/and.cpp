#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN][35];
struct bb{
	int Siz,w,r;
}b[MAXN];
int n,m;
void add(int x,int y)
{
	b[y].r=x;
	int k=0;
	while(x>0)
	{
		a[y][++k]=x%2;
		x/=2;
	}
	b[y].Siz=k;
	b[y].w=y;
	return;
}
bool cmp(bb x,bb y)
{
	if(x.Siz!=y.Siz)return x.Siz>y.Siz;
	else return x.r>y.r;
}
int And(int q)
{
	for(int i=q+1;i<=q+m;i++)
	{
		for(int j=1;j<=30;j++)
		{
			if(!a[b[i].w][j])a[b[q].w][j]=0;
		}
	}
	int k=1,ans=0;
	for(int i=1;i<=30;i++)
	{
		ans+=a[b[q].w][i]*k;
		k*=2;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		add(x,i);
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++)cout<<b[i].r<<" "<<b[i].Siz<<" "<<b[i].w<<'\n';
	for(int i=1;i<=n;)
	{
		bool flag=1;
		int p=1;
		for(;p<m;p++)
		{
			if(b[i+p].Siz!=b[i].Siz)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			cout<<And(i);
			return 0;
		}
		i+=p;
	}
	cout<<0;
	return 0;
}
