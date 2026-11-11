#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ans[N],b[N]; 
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool flag=true;
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]) flag=false;
	}
	if(flag)
	{
		for(int i=2; i<=n+1; i++)
		{
			if(a[i]!=a[i-1]) 
			{
				cout<<i-1<<' ';
			}
		}
		return 0;
	}
	for(int i=1; i<=n; i++)
	{
		memset(vis,false,sizeof vis);
		for(int j=1; j<i; j++) vis[j]=true;
		for(int j=i; j<=n; j++)
		{
			bool f=false;
			int pos=0;
			for(int q=j-1; q>=i; q--)
			{
				if(vis[q]) break;
				if(a[q]==a[j]) 
				{
					f=true;
					pos=q;
					break;
				}
			}
			if(f)
			{
				for(int q=pos; q<j; q++) vis[q]=true;
			}
		}
		memset(b,0,sizeof b);
		for(int j=i; j<=n; j++)
		{
			if(!vis[j]) b[a[j]]=1;
		}
		for(int i=1; i<=m; i++) ans[i]+=b[i];
	}
	for(int i=1; i<=m; i++) cout<<ans[i]<<" ";
	return 0;
} 

