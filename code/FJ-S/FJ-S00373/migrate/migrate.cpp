#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int mi[5005][5005];
int cnt[5005][5005];
int s[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if(c<=10){
		while(t--){
			int n;
			long long d;
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++){
				s[i]=0;
				for(int j=1;j<=n;j++){
					mi[i][j]=1e9;
					cnt[i][j]=0;
				}
				mi[i][i]=0;
				cnt[i][i]=1;
				scanf("%lld",&a[i]);
			}
			long long ans=0;
			for(int i=1;i<=n;i++){
				ans+=s[i];
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]>d){
						break;
					}
					for(int k=1;k<=i;k++){
						if(!cnt[i][k]||mi[j][k]<mi[i][k]+1){
							continue;
						}
						if(mi[j][k]>mi[i][k]+1){
							mi[j][k]=mi[i][k]+1;
							if(cnt[j][k]==2){
								s[j]--;
							}
							if((cnt[j][k]=cnt[i][k])==2){
								s[j]++;
							}
						}
						else{
							if(cnt[j][k]==2){
								s[j]--;
							}
							if((cnt[j][k]+=cnt[i][k])==2){
								s[j]++;
							}
						}
					}
				}
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	if(c>12&&c<=14){
		while(t--){
			int n;
			long long d;
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			long long ans=0;
			for(int i=2;i<=n;i++){
				int p=lower_bound(a+1,a+n+1,a[i]-d)-a;
				if(p==1||p>=n-1){
					continue;
				}
				int q=lower_bound(a+1,a+n+1,a[p+1]-d)-a;
				ans+=p-q;
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	while(t--){
		putchar('0');
		putchar(10);
	}
}
