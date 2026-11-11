#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+12;
const int SN=5055;
const int inf=0x3f3f3f3f;
const ll Inf=2e18;

int TID,T;

int n;ll d;
ll x[N];

int head[SN],to[SN*6],nex[SN*6],tot=0;
inline void mkr(int u,int v){
//	cerr<<u<<" "<<v<<endl;
	to[++tot]=v,nex[tot]=head[u],head[u]=tot; 
}
int dp[SN];
int dis[SN];bool vis[SN];
void SolveSN(){
	for(int i=1;i<=n;++i){
		if(n<=300){
			for(int j=i+1;j<=n;++j){
				if(x[j]-x[i]<=d){
					mkr(i,j);
				}else{
					break;
				}
			}
		}else{
			auto it=upper_bound(x+1,x+n+1,x[i]+d);
			it--;
			if(it==x){
				continue;
			}
			if((*it)>x[i]){
				mkr(i,it-x);
			}
			it--;
			if(it==x){
				continue;
			}
			if((*it)>x[i]){
				mkr(i,it-x);
			}
			it--;
			if(it==x){
				continue;
			}
			if((*it)>x[i]){
				mkr(i,it-x);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		queue<int> q;q.emplace(i);
		for(int j=i;j<=n;++j){
			dis[j]=inf;dp[j]=0;vis[j]=0;
		}
		dis[i]=0;dp[i]=1;
		while(!q.empty()){
			int now=q.front();q.pop();
			if(vis[now]){
				continue;
			}
			vis[now]=1;
			for(int f=head[now];f;f=nex[f]){
				int t=to[f];
				if(dis[t]>dis[now]+1){
					dis[t]=dis[now]+1;
					dp[t]=dp[now];
					q.emplace(t);
				}else if(dis[t]==dis[now]+1){
					dp[t]+=dp[now];
					dp[t]=min(dp[t],5);
				}
			}
		}
//		cerr<<"i="<<i<<":\n";
		for(int j=i;j<=n;++j){
//			cerr<<dp[j]<<" ";
			if(dp[j]==2){
//				cerr<<j<<endl;
				ans++;
			}
		}
//		cerr<<endl;
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;++i){
		head[i]=0;
	}
	for(int j=1;j<=tot;++j){
		to[j]=nex[j]=0;
	}
	tot=0;
}

void SolveB(){
	ll Ans=0;
	for(int i=1;i<=n;++i){
//		cerr<<"i="<<i<<endl;
		auto it=upper_bound(x+1,x+n+1,x[i]+d);
		it--;
		ll f1=0,f2=0,f3=0; 
		if((*it)<=x[i]||it==x){
			f1=x[i];
		}else{
			f1=(*it);
		}
		it--;
		if((*it)<=x[i]||it==x){
			f2=x[i];
		}else{
			f2=(*it);
		}
		it--;
		if((*it)<=x[i]||it==x){
			f3=x[i];
		}else{
			f3=(*it);
		}
//		cerr<<f1<<" "<<f2<<" "<<f3<<endl;
		int L=i,R=n,ans=i;
		while(L<=R){
			int mid=(L+R)>>1;
			if(x[mid]-f2<=d){
				ans=mid;
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		L=i,R=n;int ans2=n+1;
		while(L<=R){
			int mid=(L+R)>>1;
//			cerr<<"P "<<L<<" "<<R<<" "<<mid<<" "<<x[mid]<<" "<<f3<<endl;
			if(x[mid]-f3>d){
				ans2=mid;
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		if(ans<ans2){
			continue;
		}
		Ans+=ans-ans2+1;
//		cerr<<ans2<<" "<<ans<<endl;
	}
	cout<<Ans<<"\n";
}

void Solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>x[i];
	}
	if(TID<=10){
		SolveSN();
		return;
	}else if(TID==13||TID==14){
		SolveB();
		return;
	}else{
		cout<<"0\n";
	}
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	
	cin>>TID>>T;
	while(T--)Solve();
	
	return 0;
}
/*
0 2

4 2
1 2 3 4

5 2
1 2 3 4 5

0 1
4 2
1 2 3 4

0 1
8 5
1 2 5 6 8 9 10 11

0 1
5 3
-2 -1 0 1 2
*/
