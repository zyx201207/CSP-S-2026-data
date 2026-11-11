#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=2e6+50;
int n;
ll d,a[N];
int to[N];
ll ans;
int vis[N],is[N];
ll ltl[N],ltr[N],rtl[N],rtr[N];
inline void check(int L,int R){
//	cout<<"CH\n";
	for(int i=L;i<=R;i++){
//		cout<<to[i]<<" ";
		ltl[i]=ltr[i]=rtl[i]=rtr[i]=0;
		vis[i]=0;
		is[i]=0;
	}
//	cout<<'\n';
	int tmp=L,tmp1=L;
	vector<pair<int,int>> vec;
	int miku=0;
	for(int i=L;i<=R-2;i++){
		if(to[i]==i+1) continue;
		rtl[to[i]-1]=max(to[i]+1,to[to[i]-2]+1);
		if(to[to[i]]!=to[to[i]-1]){
			rtr[to[i]-1]=min(to[to[i]-1],to[i]+1);
//			miku+=max(rtr[to[i]-1]-rtl[to[i]-1]+1,0LL);
		}
		if(ltl[to[i]-1]==0 && to[to[i]-2]!=to[to[i]]){
			vec.emplace_back(to[i],miku);
			miku=0;
		}
		if(ltr[to[i]-1]==0) tmp=tmp1;
		ltl[to[i]-1]=tmp;
		ltr[to[i]-1]=i;
		if(to[to[i]]==to[to[i]-1]) is[to[i]-1]=1;
		tmp1=i+1;
	}
	vec.emplace_back(R,0);
	int idx=vec.size()-1;
	int back=n;
	for(int i=R-2;i>=L;i--){
		int x=to[i]-1;
		if(x==i) continue;
		if(vis[x]) continue;
		vis[x]=1;
		if(is[x-1]) continue;
		if(rtr[x]==0){
			rtr[x]=min(vec[idx].fi-vec[idx].se,back);
			back=rtl[x]-1;
		}
//		cout<<ltl[x]<<" "<<ltr[x]<<" "<<rtl[x]<<" "<<rtr[x]<<" "<<x<<'\n';
		ans+=max(0LL,ltr[x]-ltl[x]+1)*max(0LL,rtr[x]-rtl[x]+1);
	}
}
inline void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int id1=2,id2=3;
	int L=1;
	int id=1;
	for(int i=1;i<=n;i++){
		while(id<n && a[id+1]-a[i]<=d) id++;
		to[i]=id;
		if(a[i]+d<a[i+1]){
			check(L,i);
			L=i+1;
		}
	}
	if(L<=n) check(L,n);
	cout<<ans<<'\n';
}
int dis[5010][5010],f[5010][5010],lit[5010];
inline void solve0(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=i;j<=n;j++){
			dis[i][j]=f[i][j]=0;
		}
		lit[i]=0;
	}
	int R=n;
	int idx=n;
	for(int i=n;i>=1;i--){
		dis[i][i]=0;
		f[i][i]=1;
		lit[i]=1;
		if(i==n) continue;
		while(a[idx]-a[i]>d){
			for(int j=idx;j<=R;j++){
				lit[j]-=f[idx][j];
				if(lit[j]==0 && idx-1!=i){
					lit[j]=f[idx-1][j];
					for(int jj=idx-2;jj>i && dis[jj][j]==dis[idx-1][j];jj--) lit[j]+=f[jj][j]; 
				}
			}
			idx--;
		}
		if(idx==i) R=i;
		for(int j=i+1;j<=R;j++){
			dis[i][j]=dis[idx][j]+1;
			f[i][j]=lit[j];
			if(lit[j]==2){
//				cout<<i<<" "<<j<<'\n';
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c<=10) solve0();
		else solve();
	}
	return 0;
}
