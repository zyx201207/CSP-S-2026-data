#include<bits/stdc++.h>

#define fr(i,l,r) for(int i=(l);i<=(r);i++)
#define fo(i,l,r) for(int i=(l);i<(r);i++)
#define fd(i,r,l) for(int i=(r);i>=(l);i--)

#define LL long long

#define VI vector<int>
#define pub push_back
#define pob pop_back

#define PI pair<int,int>
#define fir first
#define sec second

using namespace std;

const int N=505,M=5e5+5;
const LL inf=1e18;

int Tid,n,m,D,Q;
int w[M];
vector<PI>nxt[M];

LL f[N][N],Ans;
void chkmn(LL &x,LL y){
	x=min(x,y);return;
}

int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(false),cin.tie(nullptr);

	cin>>Tid>>n>>m>>D>>Q;
	fr(i,1,m){
		cin>>w[i];
	}
	fr(i,1,n){
		int sz;cin>>sz;
		fr(j,1,sz){
			int x,t;cin>>x>>t;
			nxt[x].pub({i,t});
		}
	}

	fr(i,1,n)fr(j,1,n){
		f[i][j]=inf;
		if(i==j)f[i][j]=0;
	}
	fr(x,1,m){
		for(PI iti:nxt[x]){
			int i=iti.fir,t1=iti.sec;
			for(PI itj:nxt[x]){
				int j=itj.fir,t2=itj.sec;
				chkmn(f[i][j],t1+t2);
			}
		}
	}

	fr(k,1,n)fr(i,1,n){
		if(f[i][k]==inf)continue;
		fr(j,1,n)if(f[k][j]!=inf){
			chkmn(f[i][j],f[i][k]+f[k][j]);
		}
	}

	fr(_,1,Q){
		int x,y;cin>>x>>y;
		Ans=inf;
		for(PI iti:nxt[x]){
			int i=iti.fir,t1=iti.sec;
			for(PI itj:nxt[y]){
				int j=itj.fir,t2=itj.sec;
				chkmn(Ans,f[i][j]+t1+t2);
			}
		}
		Ans=Ans+w[x]+w[y];
		cout<<Ans<<"\n";
	}

	return 0;
}