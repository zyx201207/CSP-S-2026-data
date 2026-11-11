#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+3;
int n;
ll x[N],d;
int c,T;
bool special_A=true;
ll A,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			if(i==2) A=x[i]-x[i-1];
			else if(i>=3 && x[i]-x[i-1]!=A) special_A=false;
		}
		if(special_A){
			ll cnt=d/A;
			if(cnt<2) puts("0");
			else if(cnt>=n) puts("0");
			else{
				ans=max(n-cnt*2+1,0ll);
				printf("%lld\n",ans);
			}
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int tmp=0;
				for(int k=i+1;k<j;k++){
					if(x[k]-x[i]<=d && x[j]-x[k]<=d)tmp++;
					if(tmp>2) break;
				}
				if(tmp==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
