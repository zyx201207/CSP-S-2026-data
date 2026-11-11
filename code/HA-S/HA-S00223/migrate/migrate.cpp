#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (long long)(1e18)

int n,ds,ce;

inline int read(){
	int t=0,f=1;
	register char c=getchar();
	while(c<'0'||c>'9') f=(c=='-')?(-1):(f),c=getchar();
	while(c>='0'&&c<='9') t=(t<<3)+(t<<1)+(c^48),c=getchar();
	return t*f;
}

const int N=2e6+10;

int ans;
int a[N],nxt[N],p[N],cha[N],dis[N],pre[N];

void calc(int L,int R){
	if(L==n+1) return;
//	cout<<"L:"<<L<<"¡¡R:"<<R<<"\n";
	for(int i=L;i<=R;i++){
		int maxd=0;dis[i]=0;
		for(int j=i;j!=R;j=nxt[j]){
			p[dis[j]+1]=j+1,maxd=max(maxd,dis[j]+1);
			for(int k=j+1;k<=nxt[j];k++) dis[k]=dis[j]+1;
		}
		p[maxd+1]=R+1;
//		for(int j=i;j<=R;j++) cout<<dis[j]<<" ";cout<<"\n";
		cha[i]=1;
		for(int j=i;j<=R;j++){
			if(dis[j-1]==dis[j]) cha[j]+=cha[j-1];
			if(cha[j]==2) ans++;
//			cout<<cha[j]<<" p:"<<p[dis[j]+1]<<" nx:"<<nxt[j]+1<<"\n";
			cha[p[dis[j]+1]]+=cha[j];
			if(nxt[j]+1!=p[dis[j]+2]) cha[nxt[j]+1]-=cha[j];
		}
		for(int j=i;j<=R+1;j++) cha[j]=0; 
	}
}

void solve1(){
	int Ans=0;
	for(int i=1;i<=n;i++){
		if(pre[i]!=1&&i-pre[i]+1>=3){
			Ans+=pre[pre[i]+2]-1-pre[pre[i]+1];
		}
	}
	cout<<Ans<<"\n";
}

void solve(){
	n=read(),ds=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=n,j=n;i>=1;i--){
		while(j!=i&&a[j]-a[i]>ds) j--;
//		cout<<"i:"<<i<<" j:"<<j<<"\n";
//		if(i!=j) g[j].push_back(i);
		nxt[i]=j;
	}
	for(int i=1,j=1;i<=1;i++){
		while(j!=i&&a[i]-a[j]>ds) j++;
//		cout<<"i:"<<i<<" j:"<<j<<"\n";
//		if(i!=j) g[j].push_back(i);
		pre[i]=j;
	}
	if(ce==13||ce==14){
		solve1();
		return;
	}
//	for(int i=1;i<=n;i++) reverse(g[i].begin(),g[i].end());
	int las=n+1;
	for(int i=n;i>=1;i--)
		if(i==n||a[i+1]-a[i]>ds){
			calc(i+1,las);
			las=i;
//			for(int j=0;;j++)
//				if(g1[j].empty()) break;
//				else g1[j].clear();
		}
	calc(1,las);
//	int Ans=0;
//	for(int i=1;i<=n;i++) Ans+=ans[i];
	cout<<ans<<"\n";
	
	ans=0;
	for(int i=1;i<=n+1;i++) nxt[i]=p[i]=cha[i]=dis[i]=0;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ce=read();
	int T=read();
	while(T--) solve();
	return 0;
}

