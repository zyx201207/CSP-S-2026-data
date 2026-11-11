#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=2e6+5;
const int INF=2e18+5;
int a[N];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void solve(){
	int dist[305][305],dp[305][305],a[305];
	int n=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=INF;
			dp[i][j]=0;
		}
		dist[i][i]=0;
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			for(int k=i;k<=j;k++){
				if(a[j]-a[k]<=d) dist[i][j]=min(dist[i][j],dist[i][k]+1);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			int num=0;
			for(int k=i+1;k<j;k++){
				if(dist[i][k]+dist[k][j]==dist[i][j]){
					num++;
				}
				if(num>2) break;
			}
			if(num==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
void solve1(){
	int n=read(),d=read();
	for(int i=1;i<=n;i++) d=read();
	cout<<2*n+1<<'\n';
}
void solve2(){
	int n=read(),d=read(),maxx,ans=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]-a[1]<=d) maxx=i;
	}
	maxx--;
	maxx*=2;
	cout<<n-maxx+1<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	if(c<=10){
		while(T--) solve(); 
	}
	else if(c<=12){
		while(T--) solve2(); 
	}
	else {
		while(T--) solve1();
	}
	return 0;
} 
/*
0 2
5 3
-2 -1 0 1 2
*/
