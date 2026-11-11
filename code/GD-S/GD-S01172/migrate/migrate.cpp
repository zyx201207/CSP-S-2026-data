#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,a[1000005],p[1000005],ans;
bool vis[1000005];
struct zlx{
	ll s,n;
}b[1000005];
void dfs(vector<ll> v,ll len,ll l,ll r){
	if(len>0&&v[len-1]==r){
		ll s=0;
		for(int i=1;i<len;i++){
			if(abs(a[i]-a[i-1])>d) return ;
			else s++;
		}
		p[s]++;
		return ;
	}
	for(int i=l;i<=r;i++){
		if(vis[i]==0){
			vector<ll> tv=v;
			tv.push_back(i);
			vis[i]=1;
			dfs(tv,len+1,l,r);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) vis[i]=0,p[i]=0,cin>>a[i];
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(a[i]+d<a[j]){
//					b[i].s=j-1;
//					break;
//				}
//			}
//			for(int j=i+1;j>=1;j--){
//				if(a[i]-d>a[j]){
//					b[i].n=j+1;
//					break;
//				}
//			}
//		}
		ans=0;
		vector<ll> z;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(z,0,i,j);
				for(int k=1;k<=n;k++){
					if(p[k]>0){
						if(p[k]==2) ans++;
						break; 
					}
				}
				for(int k=1;k<=n;k++) p[k]=0;
			}
		}
		cout<<ans-1<<'\n';
	}
	return 0;
}
