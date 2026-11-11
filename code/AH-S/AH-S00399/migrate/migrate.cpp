#include<bits/stdc++.h>
using namespace std;
long long t,n,m,c,sum,cnt[5005][5005],a[2000005],f[5005][5005];
vector<long long>g[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==11||c==12){
		while(t--){
			scanf("%lld%lld",&n,&m);
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			long long num=a[2]-a[1];
			if(m>=2*num)printf("%lld\n",(n-1-m/num+n-1-2*(m/num)+2)*(m/num-1)/2);
			else printf("%d\n",0);
		}
	}else{
		while(t--){
			scanf("%lld%lld",&n,&m);
			sum=0;
			for(int i=1;i<=n;i++){
				g[i].clear();
				for(int j=i+1;j<=n;j++){
					cnt[i][j]=0,f[i][j]=0x3f3f3f3f;
				}
			}
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
				for(int j=i-1;j>=1;j--){
					if(a[i]-a[j]<=m)g[j].push_back(i),f[j][i]=1,cnt[j][i]=1;
					else break;
				}
			}
			for(int l=1;l<n;l++){
				for(int i=1;i<=n;i++){
					if(i+l>n)break;
					int j=i+l;
					for(auto v:g[i]){
						if(1+f[v][j]>f[i][j])continue;
						if(1+f[v][j]<f[i][j])cnt[i][j]=0;
						f[i][j]=1+f[v][j];
						cnt[i][j]+=cnt[v][j];
					}
				}
			}
			for(int i=1;i<=n;i++){
				g[i].clear();
				for(int j=i+1;j<=n;j++){
					if(cnt[i][j]==2)sum++;
					cnt[i][j]=0,f[i][j]=0x3f3f3f3f;
				}
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}
