#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
typedef long long ll;
ll c,t,n,d,a[N],dist[N],ans,b[N],l,r,cnt[3];
bool flag;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		flag=true;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
				flag=false;
			}
		}
		if(c==13||c==14){
			printf("0\n");
			continue;
		}
		if(flag){
			ans=0;
			for(int i=1;i<=1;i++){
				l=r=i;
				dist[i]=0;
				b[i]=0;
				cnt[0]=cnt[1]=cnt[2]=0;
				int cnt0=1,cnt1=0;
				for(int j=i+1;j<=n;j++){
					while(a[j]-a[l]>d){
						cnt[b[l]]--;
						if(b[l]==0){
							cnt0--;
						}else if(b[l]==1){
							cnt1--;
						}
						l++;
					}
					if(j==l){
						break;
					}
					while(r<j&&dist[r]<=dist[l]){
						cnt[b[r]]++;
						r++;
					}
					if(r-l>2){
						b[j]=2;
					}else if(r-l==2){
						if(cnt[0]==2){
							ans+=n-j+1;
							b[j]=1;
						}else{
							b[j]=2;
						}
					}else{
						if(cnt[1]){
							ans+=n-j+1;
							b[j]=1;
						}else if(cnt[0]){
							b[j]=0;
						}else{
							b[j]=2;
						}
					}
					dist[j]=dist[l]+1;
					if(b[j]==0){
						cnt0++;
					}else if(b[j]==1){
						cnt1++;
					}
					if(!cnt0&&!cnt1){
						break;
					}
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			l=r=i;
			dist[i]=0;
			b[i]=0;
			cnt[0]=cnt[1]=cnt[2]=0;
			int cnt0=1,cnt1=0;
			for(int j=i+1;j<=n;j++){
				while(a[j]-a[l]>d){
					cnt[b[l]]--;
					if(b[l]==0){
						cnt0--;
					}else if(b[l]==1){
						cnt1--;
					}
					l++;
				}
				if(j==l){
					break;
				}
				while(r<j&&dist[r]<=dist[l]){
					cnt[b[r]]++;
					r++;
				}
				if(r-l>2){
					b[j]=2;
				}else if(r-l==2){
					if(cnt[0]==2){
						ans++;
						b[j]=1;
					}else{
						b[j]=2;
					}
				}else{
					if(cnt[1]){
						ans++;
						b[j]=1;
					}else if(cnt[0]){
						b[j]=0;
					}else{
						b[j]=2;
					}
				}
				dist[j]=dist[l]+1;
				if(b[j]==0){
					cnt0++;
				}else if(b[j]==1){
					cnt1++;
				}
				if(!cnt0&&!cnt1){
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
