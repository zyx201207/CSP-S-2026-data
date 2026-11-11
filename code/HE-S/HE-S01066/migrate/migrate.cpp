#include<bits/stdc++.h>
#define ll long long
const int N = 2e6 + 10;
const int M = 5000 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
using namespace std;
inline ll read(){
	ll x=0, w=1;
	char c=getchar();
	while(c<'0' or c>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
char c[100];
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	int cnt=0;
	do{
		c[++cnt]=x%10+'0';
		x/=10;
	}while(x);
	while(cnt)putchar(c[cnt--]);
	putchar('\n');
}

int n;
ll d;
ll x[N];
ll dis[M][M];
ll cnt[M][M];
ll ans;

void solve(){
	ans=0;
	n=read();d=read();
	for(int i=1;i<=n;i++)x[i]=read();
	if(n<=3)return void(write(0));
	memset(dis,0x3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	for(int r=1,l=1;r<=n;r++){
		while(l<r and x[r]-x[l]>d)l++;
		for(int i=l;i<r;i++)dis[r][i]=1,cnt[r][i]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=k+1;i<=n;i++){
			if(i==k or dis[i][k]>=inf)break;
			if(cnt[i][k]>2)continue;
			for(int j=k-1;j>=1;j--){
				if(dis[k][j]>=inf)break;
				if(cnt[k][j]>2)continue;
				if(dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[i][k]+dis[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
				else if(dis[i][k]+dis[k][j]==dis[i][j])cnt[i][j]+=cnt[i][k]*cnt[k][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(cnt[i][j]==2)ans++;
			cnt[i][j]=0;
		}
	}
	write(ans);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read();int _=read();
	while(_--)solve();
	return 0;
}
