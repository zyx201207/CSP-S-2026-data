#include<bits/stdc++.h>
using namespace std;
#define N 2000005
#define ll long long
inline ll in(){
	ll x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
ll c,t,n,d,a[N],dp[N][2],ans,s[N][2];
inline void dfs(int x,int step){
	for (int i=n;i>x;i--){
		if (a[i]-a[x]<=d){
			dfs(i,step+1);
			if (s[i][0]==0)s[i][0]=step+1;
			if (s[i][0]==step+1)s[i][1]++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=in(),t=in();
	while (t--){
		n=in(),d=in();ans=0;
		for (int i=1;i<=n;i++)a[i]=in();
		/*for (int i=1;i<=n;i++){
			dp[i][0]=0;dp[i][1]=0;
			int cnt=0;
			for (int j=i+1,k=i;j<=n;j++){
				while (a[j]-a[k]>d)k++;
				if (a[j]-a[j-1]>d)break;
				dp[j][0]=dp[k][0]+1;dp[j][1]=k;
				if (dp[k][0]==dp[k+1][0]){
					if (dp[k][1]==dp[k+1][1]&&cnt==0){
						
					}
					break;
				}
			}
		}*/
		for (int i=1;i<=n;i++){
			for (int k=i;k<=n;k++)s[k][0]=s[k][1]=0;
			dfs(i,0);
			for (int k=i;k<=n;k++)if (s[k][1]==2)ans++;
		}
				
		printf ("%lld\n",ans);
			
	}
	return 0;
}

