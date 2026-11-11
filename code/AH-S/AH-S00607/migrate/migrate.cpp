#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long a[200005],t[5005],minn=0x3f3f3f3f;
long long w[125254];
long long dp[5005][5005],k[2005],cnt,ans,sum;
void dfs(long long x,long long y,long long mi){
	if(x==y){
		minn=min(minn,cnt);
		t[cnt]++;
		//ans++;
	}
	if(cnt>minn)return;
	for(long long i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			cnt++;
			dfs(i,y,mi);
			cnt--;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				long long mi=dp[i][j];
				dfs(i,j,mi);
				cnt=0;
				//cout<<ans<<endl;
				//cout<<minn<<endl;
				if(minn!=0x3f3f3f3f&&t[minn]==2){
					sum++;
				}
				minn=0x3f3f3f3f;
				memset(t,0,sizeof(t));
				ans=0;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
