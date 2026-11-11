#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
int cid,n,d;
int a[2000010];
int f[2000010],g[2000010],L[2000010],suf[2000010],ans;
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int r=1;r<=n;r++){
		for(int i=1;i<=r+1;i++){
			f[i]=0;
			g[i]=0;
			L[i]=0;
			suf[i]=0;
		}
		f[r]=0;
		g[r]=1;
		L[0]=r;
		suf[r]=1;
		for(int i=r-1;i>=1;i--){
			int lo=i+1,hi=r;
			while(lo<hi){
				int mid=(lo+hi+1)>>1;
				if((a[mid]-a[i])<=d) lo=mid;
				else hi=mid-1; 
			}
			if((a[lo]-a[i])>d){
				f[i]=inf;
				g[i]=0;
				break;
			}else{
				f[i]=f[lo]+1;
				g[i]=suf[L[f[lo]]]-suf[lo+1];
//				cerr<<lo<<' '<<f[lo]<<' '<<L[f[lo]]<<' '<<suf[L[f[lo]]]<<' '<<suf[lo+1]<<endl;
				if(g[i]==2){
					ans++;
				}
				L[f[i]]=i;
				suf[i]=suf[i+1]+g[i];
			}
//			cerr<<r<<' '<<i<<' '<<f[i]<<' '<<g[i]<<endl;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _;
	cin>>cid>>_;
	while(_--)solve();
	return 0;
}
