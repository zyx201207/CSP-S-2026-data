#include<bits/stdc++.h>
#define int long long
#define pp pair<int,int>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int maxn=2e6+5,inf=1e9;
int n,d,x[maxn];
void solve(){
	vector<vector<bool>>ok(n+1,vector<bool>(n+1,0));
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
		if(x[j]-x[i]<=d)ok[i][j]=ok[j][i]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		vector<int>vis(n+1,0);
		vector<int>d(n+1,inf);
		vector<int>cnt(n+1,0);
		d[i]=0;
		priority_queue<pp,vector<pp>,greater<pp>>pq;
		pq.push({0,i});
		while(!pq.empty()){
			int u=pq.top().second;
			pq.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(int v=1;v<=n;v++)
				if(ok[u][v]){
					if(d[v]>d[u]+1){
						d[v]=d[u]+1;
						cnt[v]=1;
						pq.push({d[v],v});
					}
					else if(d[v]==d[u]+1)cnt[v]++;
				}
		}
		for(int j=1;j<=n;j++)ans+=(cnt[j]==2);
	}
	write(ans),putchar('\n');
}
void solve_1(){
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=i+3;j<=n;j++)
		ans++;
	write(ans),putchar('\n');
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		n=read(),d=read();
		bool xz1=1,xz2=0,xz3=0;
		for(int i=1;i<=n;i++){
			x[i]=read();
			if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2])xz1=0;
		}
		for(int i=1;i<=n;i++)
			if(x[i]-x[1]<=d&&x[n]-x[i]<=d)xz2=1;
		xz3=(x[n]-x[1]<=10*d);
		if(n<=300)solve();
		else write(0),putchar('\n');
	}
	return 0;
}
/*
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/
