#include<bits/stdc++.h>
using namespace std;
#define int long long
//c，股份两百，分数线古迹载250 
int t,n,k,sum,a[200005],jl[200005],c;
vector<int>v[200005];
void dfs(int x,int mx,int fa){
	if(jl[x]>mx){
		jl[x]=0;
		a[x]=1;
		sum++;
		jl[fa]=min(jl[fa],1ll);
	}
	for(int i=0;i<v[x].size();i++){
		int nv=v[x][i];
		if(nv==fa)continue;
		jl[nv]=min(jl[nv],jl[x]+1);
		dfs(nv,mx,x);
	}
	jl[fa]=min(jl[fa],jl[x]+1);
}
bool check(int xx){
	for(int i=1;i<=n;i++){
		sum=1;
		memset(a,0,sizeof(a));
		memset(jl,0x3f,sizeof(jl));
		jl[i]=0;
		dfs(i,xx,-1);
		if(sum>k)continue;
		if(sum<=2)return 1;
		int cnt=sum-2;
		sum+=cnt*xx;
		if(sum<=k)return 1;
	}
	return 0;
}
int dp[200005];
void dfp(int x,int j,int fa){
	if(fa!=-1)dp[x]=dp[fa]+1;
	for(int i=0;i<v[x].size();i++){
		int nv=v[x][i];
		if(nv==fa)continue;
		dfp(nv,j+1,x);
	}
}
void solve(){
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++){
			int nu,nv;cin>>nu>>nv;
			v[nu].push_back(nv);
			v[nv].push_back(nu);
		}
		memset(dp,0,sizeof(dp));
		dfp(1,0,-1);
		int id=1;
		for(int i=1;i<=n;i++){
			if(dp[i]>dp[id])id=i;
		}
		memset(dp,0,sizeof(dp));
		dfp(id,0,-1);
		id=1;
		for(int i=1;i<=n;i++){
			if(dp[i]>dp[id])id=i;
		}
		cout<<(dp[id]+2)/3<<endl;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==7||c==11||c==12){
		solve();
	}else if(c==13||c==14){
		while(t--){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int q1,q2;
				cin>>q1>>q2;
			}
			int cnt=(n)/2+1;
			cnt-=k;
			if(k>=n/2)cout<<1<<endl;
			else{
				cout<<cnt*2<<endl;
			}
		}
	}else{
		while(t--){
			cin>>n>>k;
			for(int i=1;i<=n;i++)v[i].clear();
			for(int i=1;i<n;i++){
				int nu,nv;cin>>nu>>nv;
				v[nu].push_back(nv);
				v[nv].push_back(nu);
			}
			int l=1,r=n,ans=n;
			while(l<=r){
				int mid=l+r>>1;
				if(check(mid)){
					ans=mid;
					r=mid-1;
				}else l=mid+1;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
//7 1
//24 2
//1 2
//2 3
//1 6
//6 7
//1 4
//4 5
//1 8
//8 9
//8 10
//10 11
//10 12
//12 13
//10 14
//14 15
//14 16
//14 17
//17 18
//18 19
//19 20
//18 21
//18 22
//22 23
//23 24
//差一步美满 
