#include<bits/stdc++.h>
using namespace std;
int t,n,rpos[2000005],book[2000005];
long long dis[2000005],cnt[2000005],a[2000005],ans,m;
void bfs(int f){
	int j=f+1;
	for(int i=1;i<=n;i++)book[i]=0;
	for(int i=1;i<=n+1;i++){
		dis[i]=1e9;cnt[i]=0;
	}
	dis[f]=0;cnt[f]=1;cnt[f-1]=0;
	cnt[f+1]--; 
	for(int i=f;dis[i]<j;i++){
		cnt[i]+=cnt[i-1];
		if(cnt[i]==2)ans++;
		for(;j<=rpos[i];j++){
			if(!book[dis[i]+1])book[dis[i]+1]=j;
			dis[j]=dis[i]+1;
		}
		if(!book[dis[i]+1])continue;
		cnt[book[dis[i]+1]]+=min(3ll,cnt[i]);
		cnt[rpos[i]+1]-=min(3ll,cnt[i]);
	}
}
void work(){
	cin>>n>>m;ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1,j=1;i<=n;i++){
		while(j<=n&&a[j]-a[i]<=m)j++;
		rpos[i]=j-1;
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	cout<<ans<<"\n"; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		work();
	}
	return 0;
}
