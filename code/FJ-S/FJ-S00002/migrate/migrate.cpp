#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
long long x[MAXN];
long long d,cnt,ans;
int c,t,n,len;
void DFS(int u,int en,int sum){
	if(u==en){
		if(sum<len){
			cnt=1;
			len=sum;
		}else if(sum==len){
			cnt++;
		}
		return;
	}
	for(int nxt=u+1;nxt<=en;nxt++){
		if(x[nxt]-x[u]<=d){
			DFS(nxt,en,sum+1);
		}
	}
	return;
}
void Solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	ans=0LL;
	for(int u=1;u<n;u++){
		for(int v=u+1;v<=n;v++){
			cnt=0LL;
			len=0x3f3f3f3f;
			DFS(u,v,0);
			if(cnt==2LL){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>t;
	while(t--){
		Solve();
	}
	return 0;
}