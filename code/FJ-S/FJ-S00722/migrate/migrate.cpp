#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int c,T,n,nxt[2000005],dis[2000005],typ[2000005],cnt[2000005],cnt1[2000005];
ll x[2000005],d,ans;
inline void add(int x){
	int dex=dis[x];
	cnt[dex]++;
	if(typ[x]==0) cnt1[dex]++;
}
inline void del(int x){
	int dex=dis[x];
	cnt[dex]--;
	if(typ[x]==0) cnt1[dex]--;
}
inline void solve1(){
	ans=0;int EEE=0;
	for(int R=1;R<=n;R++){
		for(int i=1;i<=n;i++) typ[i]=dis[i]=cnt[i]=cnt1[i]=0;
		//0 wei dan,1 wei shuang,2 wei buhefa
		int r=R-1;
		for(int i=R-1;i>EEE;i--){
			int nnn=min(nxt[i],R);
			dis[i]=dis[nnn]+1;
			while(r>=nnn) del(r),r--;
			if(typ[nnn]==0&&cnt[dis[i]-1]==0) typ[i]=0;
			else if(typ[nnn]==1&&cnt[dis[i]-1]==0) typ[i]=1;
			else if(typ[nnn]==0&&cnt[dis[i]-1]==1&&cnt1[dis[i]-1]==1) typ[i]=1;
			else typ[i]=2;
			add(i);if(typ[i]==1) ans++;
			//cout<<typ[i]<<" ";
		}
		//for(int i=EEE+1;i<R;i++) cout<<typ[i]<<" ";
		//cout<<"\n";
		/*for(int i=EEE+1;i<R;i++) cout<<dis[i]<<" ";
		cout<<"\n";cout<<"djb: ";
		int st=EEE+1;while(1){
			cout<<typ[st]<<" ";st=nxt[st];
			if(st>R||st==nxt[st]) break;
		}cout<<"\n";*/
		if(nxt[R]==R) EEE=R;
	}
	cout<<ans<<"\n";
}
inline void solve2(){
	ans=0;
	ll dex=0,mi=2e18,ma=-2e18;
	for(int i=1;i<=n;i++) mi=min(mi,x[i]),ma=max(ma,x[i]);
	for(int i=1;i<=n;i++){
		if(ma-x[i]<=d&&x[i]-mi<=d){
			dex=i;break;
		}
	}
	for(int i=1;i<=dex;i++){
		if(nxt[i]>dex){
			ans+=(n-nxt[i]);
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];x[n+1]=0;
		int r=1;
		for(int l=1;l<=n;l++){
			while(x[r]-x[l]<=d&&r<=n) r++;r--;
			nxt[l]=r;
			//cout<<nxt[l]<<" ";
		}
		//cout<<"\n";
		if(c<=10) solve1();
		else if(c==13||c==14) solve2();
	}
}
