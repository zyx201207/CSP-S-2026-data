#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=4e5+10;
int ans,sum,sum_old;
int n,m;
int a[maxn];
int s[maxn][32];
bool cmp(int a,int b){
	return a>=b;
}
void temp(int i){
	int len=0;
	while(a[i]>0){
		s[i][++len]=a[i]-((a[i]>>1)<<1);
		a[i]>>=1;
	}
	s[i][0]=len;
}
bool b[maxn];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(b,1,sizeof b);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",a+i);
		temp(i);
	}
	int flag=0;
	for(int k=31;k>0;--k){
		int cnt=0;
		if(flag==0){	
			for(int i=1;i<=n;++i){
				if(s[i][k]==1){
					cnt++;
				}
			}
			if(cnt>=m){
				flag=1;
				ans++;
				for(int i=1;i<=n;++i){
					if(s[i][k]==0){
						b[i]=0;
					}
				}
			}
		}else{
			for(int i=1;i<=n;++i){
				if(s[i][k]==1&&b[i]==1){
					cnt++;
				}else{
					if(s[i][k]==0){
						b[i]=0;
					}
				}
			}
			if(cnt>=m){
				ans=ans<<1|1;
			}else{
				ans<<=1;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
/*5 3
31 3 1 15 7*/
