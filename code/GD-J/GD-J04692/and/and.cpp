#include<bits/stdc++.h>
using namespace std;
long long n,m,s[200005],maxn=-1,dis[200005],maxm=-1;
long long maxx(long long a,long long b){
	if(a>b) return a;
	else return b;
}
void dfs(int k){
	if(k>m){
		long long sum=s[dis[1]];
		for(int j=2;j<=m;j++){
			sum=sum&s[dis[j]];
		}
		maxm=maxx(maxm,sum);
		return ;
	}
	else {
		for(int i=dis[k-1]+1;i<=n;i++){
			dis[k]=i;
			dfs(k+1);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	if(m==1){
		sort(s+1,s+n+1,greater<int>());
		printf("%lld",s[1]);
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) maxn=maxx(maxn,s[i]&s[j]);
			}
		}
		printf("%lld",maxn);
	}
	else if(m==n){
		int qq=s[1];
		for(int i=2;i<=n;i++) qq=qq&s[i];
		printf("lld",qq);
	}
	else{
		dfs(1); 
		printf("%lld",maxm);
	}
	return 0;
} 
