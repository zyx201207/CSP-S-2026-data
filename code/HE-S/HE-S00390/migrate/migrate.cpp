#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=5e3;
long long C,n,d,x[N],lf[N],rf[N],lc[N],rc[N],dis[M],f[M],ans;
void solve1(){
	for(int i=1,j=1;i<=n;i++){
		while(x[i]-x[j]>d)j++;
		lf[i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(x[j]-x[i]>d)j--;
		rf[i]=j;
	}
	for(int i=1;i<=n;i++)
		lc[rf[i]]+=lc[i];
	for(int i=n;i>=1;i--)
		rc[lf[i]]+=rc[i];
	for(int i=1;i<n;i++){
		int l=lf[i+1],u=i,v=i+1,r=rf[i];
		if(lf[u]!=l||rf[v]!=r||rf[l]!=v||lf[r]!=u||l==u||v==r){
			if(rf[l]==v&&lf[r]==u&&l<u&&u<v&&v<r)
				ans++;
			continue;
		}
		ans+=lc[l]*rc[r]+(r-v)*(u-l-1)+(r-v-1)*(u-l);cerr<<l<<" "<<u<<" "<<v<<" "<<r<<"\n";
	}
	cout<<ans<<"\n";
}
void solve2(){
	for(int l=1;l<=n;l++){
		memset(f,0,sizeof(f)),memset(dis,0x3f,sizeof(dis));
		dis[l]=0,f[l]=1;
		for(int r=l+1,j=l;r<=n;r++){
			while(x[r]-x[j]>d)j++;
			for(int i=j;i<r;i++){
				if(dis[i]+1<dis[r])
					dis[r]=dis[i]+1,f[r]=0;
				if(dis[i]+1==dis[r])
					f[r]+=f[i];
			}
			if(f[r]==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
void solve(){
	cin>>n>>d,ans=0;
	for(int i=1;i<=n;i++)
		cin>>x[i],lc[i]=rc[i]=1;
	if(n>5e3) solve1();
	else solve2();
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>C>>T;
	while(T--)solve();
	return 0;
}
