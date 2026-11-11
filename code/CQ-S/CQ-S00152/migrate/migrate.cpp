#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+6;
ll a[N];
int rp[N],f[N][3][2],vis[N][3][2];
int g[N][2],Vis[N][2];
int Calc(int L,int R){
	if(L>R) return 0;
	if(R-L>=2) return Calc(R-1,R);
	if(Vis[L][R-L]) return g[L][R-L];
	int &G=g[L][R-L];
	Vis[L][R-L]=1,G=0;
	if(L==R){
		int r=rp[R];
		if(r<=R) G=0;
		else G=r-R+Calc(R+1,r);
	}else{
		int r=rp[R],l=rp[L];
		if(r<=R) G=0;
		else if(l<=R) G=r-R+Calc(R+1,r);
		else G=r-l+Calc(l+1,r);
	}return G;
}
int calc(int L,int R,int o){
	if(L>R) return 0;
	if(R-L>=3) return calc(R-2,R,0);
	if(vis[L][R-L][o]) return f[L][R-L][o];
//	cout<<"**"<<L<<" "<<R<<"\n";
	int &F=f[L][R-L][o];
	vis[L][R-L][o]=1,F=0;
	if(L==R){
		int r=rp[R];
		if(r<=R||o) F=0;
		else F=calc(R+1,r,0);
	}else if(L+1==R){
		int r=rp[R],l=rp[L];
		if(r<=R) F=0;
		else if(l<=R) F=calc(R+1,r,0);
		else{
			if(o) F=calc(l,r,1);
			else{
				if(l==r) F=l-R+Calc(R+1,r);
				else F=l-R+calc(l,r,1);
			}
		}
	}else{
		int r=rp[R],m=rp[R-1],l=rp[L];
		if(r<=R) F=0;
		else if(m<=R) F=calc(R+1,r,0);
		else if(l<=R){
			if(m==r) F=m-R+Calc(R+1,m);
			else F=m-R+calc(m,r,1);
		}else{
			if(m==r) F=m-l+Calc(l+1,m);
			else F=m-l+calc(m,r,1);
		}
	}
//	cout<<"##"<<L<<" "<<R<<" "<<F<<"\n";
	return F;
}
void work(){
	ll n,d;cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n,j=n;i>=1;i--){
		while(a[j]-a[i]>d) j--;
		rp[i]=j;
	}
	ll ans=0;
	for(int i=n;i>=1;i--) ans+=calc(i,i,0);
	cout<<ans<<"\n";
//	for(int i=1;i<=n;i++) cout<<rp[i]<<" ";
//	cout<<"\n";
//	for(int i=1;i<=n;i++) cout<<calc(i,i,0)<<" ";
	for(int i=1;i<=n;i++){
		for(int ln=0;ln<3;ln++) vis[i][ln][0]=vis[i][ln][1]=0;
		for(int ln=0;ln<2;ln++) Vis[i][ln]=0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate5.in","r",stdin);
//	freopen("out.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,T;for(cin>>c>>T;T--;) work();
}
