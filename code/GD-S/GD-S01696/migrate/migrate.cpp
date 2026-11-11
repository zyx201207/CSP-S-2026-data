#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+1;
ll c,t,n,d,ans,cnt,dis,a[N];
void dfs1(int x,int e,ll di){
	if(x==e){
		dis=min(dis,di);
		return;
	}
	for(int i=1;i<n;i++){
		if(x+i>e) return;
		if(a[x+i]-a[x]>d) return;
		dfs1(x+i,e,di+1);
	}
}
void dfs2(int x,int e,int di){
	if(di>dis) return;
	if(x==e){
		if(di==dis){
			cnt++;
		}
		return;
	}
	for(int i=1;i<n;i++){
		if(x+i>e) return;
		if(a[x+i]-a[x]>d) return;
		dfs2(x+i,e,di+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10||c>=19){
		while(t--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					dis=1e18,cnt=0;
					dfs1(i,j,0);
					dfs2(i,j,0);
					if(cnt==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}else if(11<=c&&c<=12){
		
	}else if(13<=c&&c<=14){
		
	}else{
		
	}
	return 0;
}
