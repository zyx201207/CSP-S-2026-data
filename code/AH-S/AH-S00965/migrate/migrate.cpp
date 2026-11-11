#include<bits/stdc++.h>
using namespace std;

const int N=105;

long long n,d;

long long dp[N][N],a[2000005],m[N][N];

void work(int start,int end,int now,int cnt){
	if(now==end){
		if(m[start][end]>cnt)
			dp[start][end]=0,m[start][end]=cnt;
		if(m[start][end]==cnt)dp[start][end]++; 
	}
	for(int i=now+1;i<=end&&a[i]-a[now]<=d;i++){
		work(start,end,i,cnt+1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int C,T;
	cin>>C>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		memset(m,0x3f,sizeof(m));
		//cout<<m[1][1]<<endl;
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		if(C==11||C==12){
			if(d<=(a[2]-a[1])){
				cout<<0<<endl;
			}
			else {
				int k=d/(a[2]-a[1]);
				if(k+k-1>n)cout<<0<<endl;
				else{
					cout<<n-(k+k-1)<<endl;
				}
			}
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				work(i,j,i,0);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=(dp[i][j]==2);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
