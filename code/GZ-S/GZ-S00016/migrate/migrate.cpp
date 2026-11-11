//GZ-S00016 贵阳市白云区华师一学校 闫宇凡 
#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long a[5005],d,ans,sum;
bool b[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					b[i][j]=1;
				}
				else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					continue;
				}
				sum=0;
				for(int k=i;k<=j;k++){
					if(b[i][k]&&b[k][j]){
						sum++;
					}	
				}
				if(sum==2){
					ans+=1;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
