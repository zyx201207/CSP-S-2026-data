#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,a[2000005],s[305][305],p[305][305];
int read(){
	int x=0,y=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*y;
}
void dfs(int x,int b,int l){
	if(s[b][x]==l)p[b][x]++;
	if(l<s[b][x])s[b][x]=l,p[b][x]=1;
	if(x==n)return ;
	for(int i=x+1;i<=n;i++)
		if(a[i]-a[x]<=d)
			dfs(i,b,l+1);
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	if(c==11||c==12){
		while(T--){
			n=read(),d=read();
			for(int i=1;i<=n;i++)
				a[i]=read();
			if(a[3]-a[1]>d){
				puts("0");
				continue;
			}
			int ans=0;
			for(int i=3;i<=n;i++)
				if(a[i]-a[1]<=d&&a[i+1]-a[1]>d){
					ans=max(0ll,n-i*2+3);
					break;
				}
			printf("%lld\n",ans);
		}
		return 0;
	}
	if(c==13||c==14){
		while(T--){
			n=read(),d=read();
			for(int i=1;i<=n;i++)
				a[i]=read();
			int g;
			for(int i=1;i<=n;i++)
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					g==i;
					break;
				}
			puts("0");
		}
		return 0;
	}
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				s[i][j]=INT_MAX,p[i][j]=0;
		int ans=0;
		for(int i=1;i<n;i++){
			dfs(i,i,0);
			for(int j=i+1;j<=n;j++)
				if(p[i][j]==2)
					ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
