#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000005];
long long ans=0;
long long minnn=1e18;
void dfs(int way,int end,int time,int minn){
	if(time>minn) return;
	if(ans>2) return;
	if(way==end&&time==minn){
		ans++;
		return;
	}
	if(way>end) return;
	for(int i=way+1;i<=end&&abs(a[i]-a[way])<=d;i++) dfs(i,end,time+1,minn);
}
void dfs1(int way,int end,long long time){
	if(way==end){
		minnn=min(minnn,time);
		return;
	}
	if(way>end) return;
	for(int i=way+1;i<=end&&abs(a[i]-a[way])<=d;i++) dfs1(i,end,time+1);
}
void solve(){
	memset(a,0,sizeof(a));
	cin>>n>>d;
	long long answer=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n-2;i++){
		for(int j=i+3;j<=n;j++){
			ans=0;
			minnn=1e18;
			dfs1(i,j,1);
			dfs(i,j,1,minnn);
			if(ans==2){
				answer++;
				ans=0;
			}
			else ans=0;
		}
	}
	cout<<answer<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 
