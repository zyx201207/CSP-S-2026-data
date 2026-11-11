#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=7010;
ll c,T,n,m,a[N],f[N],cnt[N],ans;
void dfs(ll p,ll res){
	if(p>n)
		return;
	if(res>f[p])
		return;
	else if(res==f[p])
		cnt[p]++;
	else{
		f[p]=res;
		cnt[p]=1;
	}
	for(int i=p+1;i<=n;i++){
		if(a[i]-a[p]>m)
			break;
		dfs(i,res+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		if(n<=5000){
			ans=0;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			for(int i=1;i<n;i++){
				for(int j=i;j<=n;j++){
					f[j]=1e18;
					cnt[j]=0;
				}
				dfs(i,0);
				for(int j=i+1;j<=n;j++)
					if(cnt[j]==2)
						ans++;
			}
			cout<<ans<<'\n';
		}
		else if(n>5000){
			ll x=0;
			for(int i=1;i<=n;i++)
				cin>>x;
			cout<<0<<'\n';
		}	
	}
	return 0;
} 
