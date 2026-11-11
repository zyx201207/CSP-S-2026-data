#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int a[maxn],mn,cnt,n,d;
void dfs(int u,int dep,int ed){
	if(u==ed){
		if(mn>dep){
			cnt=0;
			mn=dep;
		}
		else if(mn==dep) cnt++;
		cout<<"cnt = "<<cnt<<'\n';
	}
	if(u>=ed) return;
	for(int i=u+1;i<=n;i++){
		if(a[i]-a[u]<=d) dfs(i,dep+1,ed);
	}
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mn=0x3f3f3f3f,cnt=0;
				dfs(i,0,j);
				if(cnt>=2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
