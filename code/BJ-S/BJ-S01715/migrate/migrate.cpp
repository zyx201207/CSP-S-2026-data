#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10,M=5010,inf=LLONG_MAX;
int c,t,n,d,a[N],dp[M][M],an[M][M],hv[M][M],ans;
inline int read(){
    char ch=0;
    int x=0,w=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
inline int solve(int l,int r){
	if(d>=a[r]-a[l])
		return 1;
	else if(r==l+1){
		hv[l][r]=1;
		dp[l][r]=an[l][r]=0;
		return 0;
	}
	if(hv[l][r])
		return dp[l][r];
	hv[l][r]=1;
	an[l][r]=inf;
	dp[l][r]=0;
	for(int i=l+1;i<r;i++){
		solve(l,i);
		solve(i,r);
		if(!an[l][i]||!an[i][r])
			dp[l][r]=an[l][r]=0;
		if(an[l][i]+an[i][r]==an[l][r])
			dp[l][r]+=solve(l,i)*solve(i,r);
		if(an[l][i]+an[i][r]<an[l][r]){
			an[l][r]=an[l][i]+an[i][r];
			dp[l][r]=solve(l,i)*solve(i,r);
		}
	}
	if(dp[l][r]>2)
		dp[l][r]=3;
	if(dp[l][r]==2)
		ans++;
	return dp[l][r];
}
signed main(){
    freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    c=read();
    t=read();
    if(c<=10){
		while(t--){
			n=read();
			d=read();
			ans=0;
			for(int i=1;i<=n;i++){
				a[i]=read();
				for(int j=i+1;j<=n;j++){
					hv[i][j]=0;
					an[i][j]=1;
				}
			}
			solve(1,n);
			write(ans);
			//cout<<dp[1][4];
			//cout<<an[1][5];
			putchar('\n');
		}
	}
}
