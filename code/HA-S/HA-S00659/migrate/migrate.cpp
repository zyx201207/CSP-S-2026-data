#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
typedef long long LL;
const int N=2e6+10;
LL x[N];
LL qh[N],ls[N];//dan jian length
LL n,dis;
int cl(int a,int b){
	if(a==0||b==n+1) return 0;
	return abs(x[a]-x[b])<=dis;
}
bool check(int a,int b,int c,int d){
	if(cl(a,b)&&cl(a,c)&&cl(b,d)&&cl(c,d)&&!cl(a,d)) return 1;
	return 0;
}
int qhcnt[N],lscnt[N];
int qhz[N],lsz[N];
void solve(){
	cin>>n>>dis;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		qhz[i]=inf;
		lsz[i]=0;
		qhcnt[i]=lscnt[i]=0;
		qh[i]=ls[i]=0;
	}
	qh[1]=1;
	for(int i=2;i<=n;i++){
		if(cl(i,i-1)&&!cl(i-1,i+1)) qh[i]=qh[i-1]+1;
		else qh[i]=1;
	}
	ls[n]=1;
	for(int i=n-1;i>=1;i--){
		if(cl(i,i+1)&&!cl(i-1,i+1)) ls[i]=ls[i+1]+1;
		else ls[i]=1;
	}
	for(int i=1;i<=n;i++){//
		for(int j=1;j<i-1;j++){
			if(cl(j,i)&&!cl(j,i+1)){
				qhcnt[i]++;
				qhz[i]=min(qhz[i],j);
			}
		}
	}
	for(int i=n;i>=1;i--){//
		for(int j=n;j>i+1;j--){
			if(cl(j,i)&&!cl(j,i-1)){
				lscnt[i]++;
				lsz[i]=max(lsz[i],j);
			}			
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<qhcnt[i]<<" "<<lscnt[i]<<" "<<qhz[i]<<" "<<lsz[i]<<"\n";
//	}
	int ans=0;
	for(int i=1;i<n;i++){
		if(cl(i,i+1)){
			int res=0;
			res+=lscnt[i]*qhcnt[i+1];
			if(lscnt[i]&&qhcnt[i+1]) res+=ls[lsz[i]]*qh[qhz[i+1]]-1;
			//cout<<res<<" ";
			ans+=res;
		}
	}//cout<<"\n";
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
}

