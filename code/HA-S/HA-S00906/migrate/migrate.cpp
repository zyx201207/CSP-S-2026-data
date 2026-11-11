#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#define fileio(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define mems(x,v) memset(x,v,sizeof(x))
using namespace std;
namespace BaoTx{
	using ll=long long;
	const int xN=5e3+3,N=2e6+6;
	const ll INF=0x3f3f3f3f3f3f3f3fll;
	ll x[N];
	int f[2][xN][xN];
	void main(){
		int c,t;
		cin>>c>>t;
		while(t--){
			int n;
			ll d;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			if(c<=10){
				ll ans=0;
				for(int i=n;i>=1;i--){
					int p=upper_bound(x+1,x+1+n,x[i]+d)-x;
//					cout<<p<<"\n";
					for(int j=i+1;j<p;j++){
						f[0][i][j]=f[1][i][j]=1;
					}
					for(int j=p;j<=n;j++){
						ll mn=INF,cnt=0;
						for(int k=i+1;k<p;k++){
							if(!f[1][k][j]) continue;
							if(f[0][k][j]<mn){
								mn=f[0][k][j];
								cnt=0;
							}
							if(f[0][k][j]==mn) cnt+=f[1][k][j];
						}
						f[0][i][j]=mn+1;
						f[1][i][j]=cnt;
						if(cnt==2){
//							cout<<i<<" "<<j<<" "<<mn<<" "<<cnt<<"\n";
							ans+=1;
						}
					}
				}
//				for(int i=1;i<=n;i++){
//					for(int j=1;j<=n;j++){
//						cout<<f[0][i][j]<<","<<f[1][i][j]<<" \n"[j==n];
//					}
//				}
				cout<<ans<<"\n";
			}else if(c>=13&&c<=14){
				int l=n+1,r=0;
				for(int i=1;i<=n;i++){
					if(x[i]-d<=x[1]&&x[i]+d>=x[n]){
						l=min(l,i);
						r=max(r,i);
					}
				}
				if(r-l+1!=2) cout<<"0\n";
				else{
					ll ans=0;
					for(int i=1;i<=l-1;i++){
						int p=upper_bound(x+1,x+1+n,x[i]+d)-x;
						ans+=n-p+1;
					}
					cout<<ans<<"\n";
				}
			}
		}
	}
}
int main(){
	fileio(migrate);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	BaoTx::main();
	return 0;
}