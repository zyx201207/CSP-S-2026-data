#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i8;
const ll N=2e6+7,inf=(1ll<<60),mod=1e9+7;
using namespace std;
ll n,d,ans,c,t,sz;
ll a[N],lmn[N],f[N],g[N],p[N];
vector <ll> v;
//task a: j-i mod [cha/d]   (suan)
//task b: { j-i>d && j-mid+1<=d ^ mid+1-i<=d   } (two-point)
// task c: unkown
void solve(){
	if(sz<=2) return;
	lmn[1]=1;
	for(int i=2;i<=sz;i++){
		ll l=lmn[i-1];
		while(p[i]-p[l]>d)l++;
		lmn[i]=l;
	}
	for(int i=3;i<=sz;i++){
		if(lmn[i]!=i-1) ans+=lmn[lmn[i]+2]-lmn[lmn[i]+1];
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=2){
			cout<<"0\n";
			continue;
		}
		lmn[1]=1;
		for(int i=2;i<=n;i++){
			ll l=lmn[i-1];
			while(a[i]-a[l]>d)l++;
			lmn[i]=l;
//			cout<<lmn[i]<<' ';
		}
//		cout<<endl;
		if(c<=6){
			for(ll i=1;i<=n;i++){
				f[i]=0,g[i]=1;
				for(int j=i+1;j<=n;j++){
					f[j]=inf;
					for(int k=max(i,lmn[j]);k<j;k++){
						if(f[j]>f[k]){
							g[j]=g[k],f[j]=f[k];
						}else if(f[j]==f[k]){
							g[j]+=g[k];
						}
					}
					f[j]++;
//					cout<<i<<' '<<j<<' '<<f[j]<<' '<<g[j]<<endl;
					if(g[j]==2&&f[j]<(inf>>2)) ans++; 
				}
			}	
			cout<<ans<<endl;
		}else if(13<=c&&c<=14){
			for(int i=3;i<=n;i++){
				if(lmn[i]!=i-1) ans+=lmn[lmn[i]+2]-lmn[lmn[i]+1];
			}
			cout<<ans<<endl;
		}else{
			ll l=1,mid=1;
			a[n+1]=inf;
			for(int r=1;r<=n+1;r++){
				if(a[r]-a[l]<=d) mid=r;
				if(a[r]-a[mid]>d){
					solve();
					l=mid=r,sz=1,p[1]=a[r];
				} 
				p[++sz]=a[r];
			}
			cout<<ans;
		}
		
	}
}

