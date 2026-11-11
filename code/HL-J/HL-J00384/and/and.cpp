#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
ll a[N];ll n,m,c[N],d[N];
ll b[N];//ÏÖÔÚ´æµÄ 
bool vis[N];
ll ans=0;
ll cnt=0;
void dfs(ll pos){
	for(int i=0;i<n;i++){
		if(pos==n){
			for(int j=1;j<m;j++){
				b[j]=b[j]&b[j-1];
			}ans=max(ans,b[m-1]);
			memset(b,0,sizeof(b));
			cnt=0;
			pos=0;
		}if(vis[i]==0){
				b[cnt++]=a[i];
				vis[i]=true;
				dfs(pos+1);
				vis[i]=false;
			}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll maxx=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[i]=a[i];
		d[i]=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<=2000){
		if(m==1){
			cout<<maxx;
			return 0;
		}

	}		
	if(m==n){
		for(int i=1;i<=n;i++){
			c[i]=c[i]&c[i-1];
		}cout<<c[n];
		return 0;
	}
	if(m==2){
		ll anss=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				
				
				anss=max(anss,d[i]&d[j]);
			} 
		}cout<<anss;
		return 0;
	}
	
	dfs(0);
	cout<<ans;
	return 0;
}
