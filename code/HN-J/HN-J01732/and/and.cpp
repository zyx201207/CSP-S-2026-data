#include<bits/stdc++.h>

using namespace std;

bool rjz[200010][32];
long long sum[32];
long long ans,n,m;
void ddfs(long long i,long long x,long long j){
	if(x==0)return;
	rjz[i][j]=x%2;
	x/=2;
	ddfs(i,x,j+1);
}
void dfs(long long i){
	for(long long j=0;j<=i;j++){
		sum[j]=0;
		for(long long z=1;z<=n;z++){
			if(rjz[z][j]==1)sum[j]++;
		}
	}
	i--;
	for(i=i;i>=0;i--){
		if(sum[i]>=m){
			long long x=1;
			for(long long j=1;j<=i;j++)x*=2;
			ans+=x;
			for(long long z=1;z<=n;z++){
				if(rjz[z][i]==0){
					for(long long j=0;j<=i;j++){
						rjz[z][j]=0;
					}
				}
			}
			dfs(i);
			break;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		long long x;
		cin>>x;
		ddfs(i,x,0);
	}
	dfs(31);
	cout<<ans;
	return 0;
}

