#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define psb push_back
#define f(i,l,r) for(int i=l,R##R=r;i<=R##R;++i)
#define g(i,l,r) for(int i=l,R##R=r;i>=R##R;--i)
const int N=2e6+10;
int C,T,n,pr[N],nx[N],l[N],r[N],lp[N],rp[N],ln[N],rn[N];
ll as,d,a[N];
int qr(int p){
	if(!rp[p]) return 1;
	int l=max(p+1,lp[p]),r=min(nx[p]-1,rp[p]);
	return 1+max(0,r-l+1);
}
int ql(int p){
	if(!ln[p]) return 1;
	int l=max(pr[p]+1,ln[p]),r=min(p-1,rn[p]);
	return 1+max(0,r-l+1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d; as=0;
		f(i,1,n) cin>>a[i],rp[i]=ln[i]=0;
		for(int i=1,j=1;i<=n;++i){
			while(j<=n&&a[j]-a[i]<=d) ++j;
			nx[i]=j-1,rn[j-1]=i;
			if(!ln[j-1]) ln[j-1]=i;
		}
		for(int i=n,j=n;i;--i){
			while(j&&a[i]-a[j]<=d) --j;
			pr[i]=j+1,lp[j+1]=i;
			if(!rp[j+1]) rp[j+1]=i;
		}
		g(i,n,1) r[i]=(pr[nx[i]]==i?r[nx[i]]:0)+qr(i);
		f(i,1,n) l[i]=(nx[pr[i]]==i?l[pr[i]]:0)+ql(i);
		f(i,1,n){
			int j=nx[nx[i]];
			if(j>nx[i]&&nx[i]-pr[j]==1) as+=(ll)(pr[pr[j]]==i?l[i]:1)*r[j]-1;
		}
		f(j,1,n){
			int i=pr[pr[j]];
			if(j>nx[i]&&nx[i]-pr[j]==1&&nx[nx[i]]!=j) as+=l[i]-1;
		}
		f(i,1,n){
			int l=max(nx[i]+1,lp[nx[i]-1]),r=min(n,rp[nx[i]-1]);
			as+=max(0,r-l+1);
		}
		cout<<as<<'\n';
	}
	return 0;
}
