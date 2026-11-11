#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,dis[N],ok[N];
long long d,a[N],ans;
void dfs(int x,int sum){
	if(dis[x]>sum){
		dis[x]=sum;
		ok[x]=1; 
	}
	else if(dis[x]==sum){
		ok[x]++;
	}
	else if(dis[x]<sum) return ;
	for(int i=x+1;i<=n;i++){
		if((a[i]-a[x])<=d) dfs(i,sum+1);
		else return ;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ok[i]=0;
				dis[j]=n;
			}
			dfs(i,0);
			for(int j=i;j<=n;j++){
				if(ok[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

