#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10,inf=2e9;

ll a[N];
int l[N],r[N],d[N],f[N];
void Solve(){
	int n;ll D,ans=0;
	cin>>n>>D;
	for(int i=1,j=1;i<=n;++i){
		cin>>a[i];
		while(a[i]-a[j]>D)++j;
		l[i]=j;
//		cout<<l[i]<<" \n"[i==n];
	}
	for(int L=1;L<=n;++L){
		d[L]=0,f[L]=1;
		for(int i=L+1,j=L;i<=n&&l[i]<i;++i){
			int k=max(L,l[i]);
			d[i]=d[k]+1;
			if(d[i]>d[i-1])j=i;
			f[i]=j-k>2?3:min(3,f[k]+(j-k>1?f[k+1]:f[0]));
			if(f[i]==2)++ans;
//			cout<<f[i]<<" \n"[i==n];
		}
	}
	cout<<ans<<'\n';
}
void SolveA(){
	int n;ll D;
	cin>>n>>D;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	ll x=D/(a[2]-a[1]);
	cout<<(x<2?0:max(0ll,n-2*x+1))<<'\n';
}
void SolveB(){
	int n;ll D,ans=0;
	cin>>n>>D;
	for(int i=1,j=1;i<=n;++i){
		cin>>a[i];
		while(a[i]-a[j]>D)++j;
		l[i]=j;
	}
	for(int i=n,j=n;j;--j){
		while(a[j]-a[i]>D)--j;
		r[i]=j;
	}
	int k=0;
	for(int i=1;i<=n;++i)
		if(l[i]==1&&r[i]==n){
			k=i;break;
		}
	for(int i=1;i<k;++i)
		if(r[i]==k+1)ans+=n-r[i];
	for(int i=n;i>k;--i)
		if(l[i]==k-1)ans+=l[i]-1;
	cout<<ans<<'\n';
}
int main(){
//	freopen("migrate4.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int _c,T;cin>>_c>>T;
	if(_c<=10)while(T--)Solve();
	else if(_c<=12)while(T--)SolveA();
	else if(_c<=14)while(T--)SolveB();
	return 0;
}
