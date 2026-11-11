#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int P(1e9+7);
ll kuaishumi(ll x,ll b){
	if(!b)return 1;
	ll t(kuaishumi(x*x%P,b/2));
	if(b&1)t=t*x%P;
	return t; 
} 
const int MXN(5e5+6);
ll c,n,m,d,q;
ll a[MXN];
ll w[MXN];
const int MXR(5e2+5);
ll mtx[MXR][MXR];
ll k[MXR];
vector<pair<int,ll> >Rd[MXN]; // Road Walk time 
inline int read(){// 
	int f=0,k=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')k=-1;
	for(;isdigit(c);c=getchar())f=(f<<3)+(f<<1)+c-'0';
	return k*f;
}
signed main(){
//	int T0(clock());
//	ios::sync_with_stdio(0);cin.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int _,__;
			_=read();__=read();
			Rd[_].push_back({i,__});
		}
	}
//	int T1(clock());
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		mtx[i][j]=0x3f3f3f3f3f3f3f3f;
		mtx[i][i]=0;
	}
//	int T2(clock());
	for(int i=1;i<=m;i++)
		for(auto j:Rd[i])
			for(auto k:Rd[i])
				mtx[j.first][k.first]=min(mtx[j.first][k.first],j.second+k.second);
	
//	int T3(clock());
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(mtx[i][j]!=0x3f3f3f3f3f3f3f3f)
				for(int k=1;k<=n;k++)
					mtx[j][k]=min(mtx[j][k],mtx[j][i]+mtx[i][k]);
	}
//	int T4(clock());
	while(q--){
		int _,__;
		_=read();__=read();
		ll res=0x3f3f3f3f3f3f3f3f;
		for(auto i:Rd[_]){
			for(auto j:Rd[__]){
				res=min(res,mtx[i.first][j.first]+w[_]+w[__]+i.second+j.second);
			}
		}
		if(_==__)res=0;
		cout<<res<<'\n';
	}
//	int T5(clock());
//	cerr<<"USE TIME "<<T5-T4<<' '<<T4-T3<<' '<<T3-T2<<" "<<T2-T1<<" "<<T1-T0<<endl;
//	cerr<<"TOT "<<T5-T0<<endl;
	return 0;
}
