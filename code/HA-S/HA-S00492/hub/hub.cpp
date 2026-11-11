#include <bits/stdc++.h>
#define int long long
#define inf 1e18
#define F(i,l,r) for(int i=l;i<=r;i++)
#define E(i,r,l) for(int i=r;i>=l;i--)
#define Luogu return
#define _DEQUE_ 0
using namespace std;

const int N=1e3+5;

void fre(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}

int f[N][N];

int count(int x){
	int res=0;
	while(x){
//		cout<<x%2;
		res+=x%2;
		x/=2;
	}
	return res;
}

int fa[N];

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

bool check(int x,int n){//判断连通性
	unordered_map<int,int>mp;
	int res=0;
	F(i,1,n)fa[i]=i;
	for(int i=1;i<=n;i++){
		if((x>>i-1)%2){
			for(int j=1;j<=n;j++){
				if(j!=i&&(x>>j-1)%2&&f[i][j]==1){
					i=find(i);
					j=find(j);
					if(i!=j){
						fa[i]=j;
					}
				}
			}
		}
	}
	F(i,1,n){
		if((x>>i-1)%2){
			if(mp[find(i)]==0){
				mp[find(i)]++;
				res++;
			} 
		}
	}
	return res<=2;
}

void solve(){
	int n,q;
	cin>>n>>q;
	F(i,1,n){
		F(j,1,n){
			f[i][j]=inf;
		}
	}
	F(i,1,n-1){
		int u,v;
		cin>>u>>v;
		f[u][v]=1;
		f[v][u]=1;
	}
	F(k,1,n){
		F(i,1,n){
			F(j,1,n){
				if(i==j)f[i][i]=0;
				else f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	int ans=inf;
	F(i,1,(1ll<<n)-1){
		if(count(i)==q&&check(i,n)){
//			cout<<"CAN";
			int maxx=-1;
			F(j,1,n){
				int minn=inf;
				F(k,1,n){
					if((i>>k-1)%2==1){
//						cout<<j<<" "<<k<<" "<<f[j][k]<<endl;
						minn=min(minn,f[j][k]);
					}
				}
				maxx=max(maxx,minn);
			}
			ans=min(ans,maxx);
//			cout<<ans<<endl;
		}
//		cout<<endl;
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	fre();
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}




	Luogu _DEQUE_;
}
/*
呜呜呜怎么能这样啊
只有152喂狗呢/ll/ll/ll
暴力难写难想/ll/ll/ll 
*/
