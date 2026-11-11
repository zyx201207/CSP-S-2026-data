#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=ch=='-',ch=getchar();
	do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(ch>='0'&&ch<='9');
	return f?-x:x;
}
int C,T,n,d,a[2000001],dp[5001][5001],f[5001][5001],s;
signed main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	C=rd(),T=rd();
	while(T--){
		n=rd(),d=rd(),s=0;
		for(int i=1;i<=n;i++)a[i]=rd();memset(dp,0,sizeof(dp)),memset(f,0,sizeof(f));
		for(int i=1;i<n;i++){
			if(a[i+1]-a[i]>d)n=i;
		}
		for(int len=2;len<=n;len++){
			for(int i=1,j=len;j<=n;i++,j++){
				for(int k=i;k<j;k++){
					if(a[j]-a[k]>d)continue;
					if(k==i){dp[i][j]=1,f[i][j]=1;continue;}
					if(!f[i][j]||f[i][k]+1<f[i][j])dp[i][j]=0,f[i][j]=f[i][k]+1;
					if(f[i][j]==f[i][k]+1)dp[i][j]+=dp[i][k];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)s+=(dp[i][j]==2);
		} 
		printf("%lld\n",s);
	}
	return 0;
}//如果幸福有颜色，那一定是被终末之红染尽的蓝色。
