#include<iostream>
using namespace std;
typedef long long ll;
const int si=5e3+10,msi=2e6+10;
int n,to[msi];
ll x[msi],d;
int dp[si][si],ans=0,lo[si][si];
void pianfen(){
	if(to[1]>=2)printf("%d\n",max(n-2*to[1]+1,0));
	else printf("0\n");
}
int mian(){
	scanf("%d%lld",&n,&d),ans=0;
	for(int i=1;i<=n;i++)
		scanf("%lld",&x[i]);
	bool pf=1;
	ll dis=x[2]-x[1];
	for(int i=3;i<=n;i++){
		if(x[i]-x[i-1]!=dis){
			pf=0;
			break;
		}
	}
	int lx=1;
	for(int i=1;i<=n;i++){
		lx=max(lx,i);
		while(lx+1<=n&&x[lx+1]-x[i]<=d)++lx;
		to[i]=lx-i;
		if(pf){
			pianfen();
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=lo[i][j]=-1;
	for(int l=1;l<n;l++){
		for(int i=1;i+l<=n;i++){
			int j=i+l,cnt=0;
			if(to[i]>=l){
				dp[i][j]=1,lo[i][j]=1;
				continue;
			}if(lo[i+to[i]][j]==-1){
				dp[i][j]=0;
				continue;
			}lo[i][j]=lo[i+to[i]][j]+1;
			for(int k=to[i];k>=1;k--){
				if(lo[i][j]!=lo[i+k][j]+1)continue;
				cnt+=dp[i+k][j];
				if(dp[i+k][j]==0)break;
				if(cnt>2)break;
			}dp[i][j]=cnt;
			if(cnt==2)++ans;
		}
	}printf("%d\n",ans);
	return 0;
}
int kkksc_19;
int t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	scanf("%d%d",&kkksc_19,&t);
	while(t--)mian();
	return 0;
}
/*
16:02 ↑ ↑ ↑ ↑ ↑ ！*4
16:02想看六花了 
17:18拿到了部分分，大概40分？ 
18:02又尝试性质A ，48分？ 
*/
