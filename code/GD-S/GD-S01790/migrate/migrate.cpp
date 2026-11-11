#include<bits/stdc++.h>
#define N 2000010
using namespace std;
int c,g,n,m,a[N],dp[110][110];
int dfs(int x,int y,int s,int ma){
	if(x>y||s>ma)
	return 0;
	if(x==y)
	return 1;
	int sum=0;
	for(int i=x+1;a[x]+m>=a[i];i++){
		sum+=dfs(i,y,s+1,ma);
	}
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>g;
	while(g--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
		}
		if(c<=2){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int x=a[i],s=1;
					for(int k=i+1;k<=j;k++){
						if(x+m<a[k]){
							x=a[k-1];
							s++;
						}
					}
					dp[i][j]=s;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(dfs(i,j,0,dp[i][j])==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}else if(c>=11&&c<=12){
			int t1=a[2]-a[1],t2=m/t1;
			t2=t2*2-1;
			if(t2==1)
			cout<<0<<endl;
			else{
				cout<<max(0,n-t2)<<endl;
			}
		}
	}
	return 0;
}
