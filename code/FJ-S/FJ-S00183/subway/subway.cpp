#include<bits/stdc++.h>
#define int long long
#define N 505
#define M 500005
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(-x);
		return;
	}
	if(x>9)print(x/10);
	putchar(x%10+48);
}
int c,n,m,d,q;
int g[N][N],l[M],tot[N];
unordered_map<int,int>mp[N]; 
vector<int>a[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	memset(g,0x3f,sizeof g);
	for(register int i=1;i<=m;i++)l[i]=read();
	for(register int i=1;i<=n;i++){
		g[i][i]=0;
		tot[i]=read();
		for(register int j=1;j<=tot[i];j++){
			int tmp=read();
			mp[i][tmp]=read();
			a[tmp].push_back(i); 
			for(register int k:a[tmp]){
				g[k][i]=g[i][k]=min(g[i][k],mp[i][tmp]+mp[k][tmp]);
			}
		}
	}
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=n;j++)
			for(register int k=1;k<=n;k++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	while(q--){
		int x,y,ans=1145141919810000;
		x=read();y=read();
		for(auto i:a[x]){
			for(auto j:a[y]){
				ans=min(ans,g[i][j]+mp[i][x]+mp[j][y]);
			}
		}
		print(ans+l[x]+l[y]);
		puts("");
	}
	return 0;
}

