#include<bits/stdc++.h>
using namespace std;
const long long N=505;
const long long INF1=1e15;
long long a[N];
long long s[N][N][3];
long long t[N][N],l[N][N],x[N],dp[N],k[N][N],sum[N];
bool flag[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		for(int j=1;j<=x[i];j++){
			scanf("%lld%lld",&l[i][j],&t[i][j]);
			sum[l[i][j]]++;
			s[l[i][j]][sum[l[i][j]]][1]=i;
			s[l[i][j]][sum[l[i][j]]][2]=j;
		}
	}
	for(int i=1;i<=m;i++){
		for(int z=1;z<=m;z++){
			dp[z]=INF1;
		}
		long long st=i;
		int head=1,tail=1;
		dp[head]=st,k[st][st]=0,flag[st][st]=true;
		while(head<=tail){
			for(int z=1;z<=sum[dp[head]];z++){
				for(long long z2=1;z2<=x[s[dp[head]][z][1]];z2++){
					int xx=l[s[dp[head]][z][1]][z2];
					if(flag[st][xx]==false){
						tail++;
						dp[tail]=xx;
						k[st][xx]=k[st][dp[head]]+t[s[dp[head]][z][1]][s[dp[head]][z][2]]+t[s[dp[head]][z][1]][z2];
						flag[st][xx]=true;
					}else{
						k[st][xx]=min(k[st][xx],k[st][dp[head]]+t[s[dp[head]][z][1]][s[dp[head]][z][2]]+t[s[dp[head]][z][1]][z2]);
					}
				}
			}
			head++;
		}
	}
	for(int i=1;i<=q-1;i++){
		int x1,y1;
		scanf("%d%d",&x1,&y1);
		printf("%lld\n",k[x1][y1]+a[x1]+a[y1]);
	} 
	int x1,y1;
	scanf("%d%d",&x1,&y1);
	printf("%lld",k[x1][y1]+a[x1]+a[y1]);
}
