#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int N=5e4+10;
int c,n,m,d,q,a[N],k[550],z[550][N],t[550][N],dp[550][N];
long long dfs(int l,int r,int x,long long sum,int xx){
	if(x==r){
		return sum;
	}
	for(int i=1;i<=n;i++){
		if(z[i][1]==x||z[i][2]==x){
			return dfs(l,r,x,sum+t[i][x],i);
		}
	}
	return dfs(l,r,z[xx][1],sum,xx);
	return dfs(l,r,z[xx][2],sum,xx);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			z[i][j]=read();
			t[i][j]=read();
		}
	}
	if(c<=11&&c>=7){
		while(q--){
			long long x,y,sum=0,ans=0;
			x=read();
			y=read();
			for(int i=1;i<=n;i++){
				if(z[i][1]==x)
					long long ans=dfs(x,y,x,sum,i);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
