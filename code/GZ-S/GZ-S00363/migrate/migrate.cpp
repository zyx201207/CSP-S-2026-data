//刘骏瑞 贵阳市清华中学 GZ-S00363 
#include<bits/stdc++.h>
using namespace std;
const long long N=10000+5;
int dy[20005], dp[N][N],mdp[N][N];
void check(int a,int j,int k,int n,int d){
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(sum+dy[i]>=d){
			cnt++;
			sum=dy[i];
		}
	}
	if(cnt<=k){
		if(k<mdp[a][j]){
			mdp[a][j]=k;
			dp[a][j]=1;
		}
		else{
			dp[a][j]++;
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		long long sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>dy[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mdp[i][j]=n;
			}
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=j-1;k++){
				check(i,j,k,n,d);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]==2) sum++;
		}
	}
	cout<<sum<<endl;
	}
	return 0;
}
