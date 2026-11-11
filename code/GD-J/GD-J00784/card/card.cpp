#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
ll n,m,w,a[500010],nxt[500010][20],lst[500010];
ll ans[500010],c[500010],f[500010],k[500010];
void build(){
	rep(i,1,19){
		rep(j,1,n){
			if(nxt[j][i-1]<=n) nxt[j][i]=nxt[nxt[j][i-1]][i-1];
		}
	}
	return;
}
int jump(int x){
	per(i,19,0){
		if(nxt[x][i]<=n) x=nxt[x][i];
	}
	return x;
} 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	rep(i,1,n+1) rep(j,0,19) nxt[i][j]=n+1;
	rep(i,1,n){
		cin >> a[i];
		nxt[lst[a[i]]][0]=i;
		lst[a[i]]=i;
	}
	rep(i,1,n){
		if(nxt[i][0]<=n) f[i]=1;
	}
	f[n+1]=1;
	w=n+1;
	per(i,n,1){
		k[i]=w-1;
		if(f[i]==1) w=i;
	}
	build();
	rep(i,1,n){
		int p=i;
		while(p<=n){
			if(nxt[p][0]<=n) p=jump(p);
			c[k[p]+1]--;c[p]++;p=k[p]+1;
		}
	}
	rep(i,1,n) c[i]+=c[i-1];
	rep(i,1,n){
		ans[a[i]]+=c[i];
	}
	rep(i,1,m) cout << ans[i] << " ";
	return 0;
}
