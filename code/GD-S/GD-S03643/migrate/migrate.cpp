#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
#define getc() (uu==vv&&(vv=(uu=In)+fread(In,1,1<<15,stdin),uu==vv)?EOF:*uu++)
char In[1<<15],*uu=In,*vv=In;
template<class T>
void R(T &x){
	char c=getc();bool f=0;x=0;
	for(;!isdigit(c);f|=(c=='-'),c=getc());	
	for(;isdigit(c);x=(x<<3)+(x<<1)+(c^48),c=getc());	
	f&&(x=-x);
}
using ll = long long;
const int N=2e6+5;
int n,f[N][2],cl[N],cr[N];ll d,a[N];
void solve(){
	R(n),R(d);cl[0]=1,cr[n+1]=n;bool f=true;
	rep(i,1,n)R(a[i]),f[i][0]=0,f[i][1]=0;
	rep(i,1,n){
		cl[i]=cl[i-1],cr[i]=max(cr[i-1],i);
		while(a[i]-a[cl[i]]>d)++cl[i];
		while(cr[i]<n&&a[cr[i]+1]-a[i]<=d)++cr[i];
		int x=i-cl[i];f[i][0]=x;
		if(cl[i]>1||cr[i]<n)f=false;
	}ll ans=0;
	if(f)return cout<<0<<'\n',void();
	rep(i,1,n){
		rep(j,1,i-1){
			if(cr[j]>=i)continue;
			int x=cr[j]-cl[i]+1;
			//cout<<i<<" "<<j<<" "<<x<<" "<<f[j][0]<<" "<<f[j][1]<<'\n';
			if(x==1)f[i][0]+=f[j][0]+1,f[i][1]+=f[j][1];
			if(x==2)f[i][1]+=f[j][0]+1;
		}ans+=f[i][1];//cout<<"Calc:"<<i<<" "<<f[i][0]<<" "<<f[i][1]<<'\n';
	}cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;R(c),R(T);
	while(T--)solve();
	return 0;
}
