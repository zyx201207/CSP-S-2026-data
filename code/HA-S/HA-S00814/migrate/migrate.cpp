#include<bits/stdc++.h>
#define N 5010
#define ll long long
using namespace std;
ll c,t,n,a[N][N],cnt[N][N];
ll x[N],d,ans;
int main(){
	freopen("migrate.in ","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==j){
				    a[i][j]=0;
			    }
				else if(abs(x[j]-x[i])<=d) a[i][j]=1;
				else{
				    a[i][j]=a[j][i]=100000000;
				    cnt[i][j]=0;
				    continue;
				}
				cnt[i][j]=1;
				a[j][i]=a[i][j];
			}
		}
		for(int k=1;k<=n;k++){
		    for(int i=1;i<=n;i++)
		        for(int j=1;j<=n;j++){
		        	if(a[i][j]>a[i][k]+a[k][j]){
		        		a[i][j]=a[i][k]+a[k][j];
		        		cnt[i][j]=cnt[i][k]*cnt[k][j];
		        	}
		        	else if(a[i][j]==a[i][k]+a[k][j]&&i!=k&&k!=j){
		        		cnt[i][j]+=cnt[i][k]*cnt[k][j];
		        	}
		        }
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=i+1;j<=n;j++){
	        	if(cnt[i][j]==2&&a[i][j]>1&&a[i][j]<100000000) ans++;
	        }
	    }
	    printf("%d\n",ans);
	}
	return 0;
}
