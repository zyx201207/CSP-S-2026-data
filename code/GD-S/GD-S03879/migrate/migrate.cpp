#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int INF=0x3f3f3f3f,P=998244353;
const ll LINF=0x3f3f3f3f3f3f3f3f;
const int N=2e6+5;
int c,t,n;
ll d;
ll x[N];
ll a;
const int lN=405;
ll dis[lN][lN];
int cnt[lN][lN];

inline void reset(){
	if(n<=400){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=dis[j][i]=LINF;
			}
			dis[i][i]=0;
		}
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ifstream cin("migrate.in");
	ofstream cout("migrate.out");
	for(int i=1;i<lN;++i){
		for(int j=1;j<lN;++j) dis[i][j]=dis[j][i]=LINF;
		dis[i][i]=0;
	}
	for(cin>>c>>t;t--;reset()){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		if(n<=400){
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n and x[j]-x[i]<=d;++j){
					dis[i][j]=dis[j][i]=1;
					cnt[i][j]=cnt[j][i]=1;
				}
			}
			for(int i=1;i<=n;++i){
				for(int k=i+1;k<=n;++k){
					if(dis[i][k]==LINF) continue;
					for(int j=k+1;j<=n;++j){
						if(dis[k][j]==LINF) continue;
						if(dis[i][k]+dis[k][j]<dis[i][j]){
							cnt[i][j]=cnt[j][i]=1;
							dis[i][j]=dis[i][k]+dis[k][j];
						}else if(dis[i][k]+dis[k][j]==dis[i][j]){
							++cnt[i][j];
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					if(cnt[i][j]==2) ++ans;
				}
			}
			cout<<ans<<"\n";
		}else{
			a=x[2]-x[1];
			if(d<a*2){
				cout<<"0\n";
				continue;
			}
			cout<<max(0ll,(n-((d/a)*2-1)))<<"\n";
		}
		
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 1
6 4
1 2 3 4 5 6
*/
