#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
long long vis[32];
bool vis2[200005];
void dfs(int u){
	bool flag=0;
	for(int i=u;i>=0;i--){
		if(vis[i]>=m){
			u=i;
			flag=1;
			break;
		}
	}
	if(!flag)return;
	ans+=(1<<u);
	for(int i=1;i<=n;i++){
		if(!(a[i]&(1<<u))&&!vis2[i]){
			vis2[i]=1;
			int tmp=a[i],cnt=0;
			while(tmp){
				if(tmp%2)vis[cnt]--;
				cnt++,tmp/=2;
			}
		}
	}
	dfs(u-1);
}
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int tmp=a[i],cnt=0;
		while(tmp){
			if(tmp%2){
				vis[cnt]++;
			} 
			cnt++,tmp/=2;
		}
	}
	dfs(29);cout<<ans<<endl;
	return 0;
}
