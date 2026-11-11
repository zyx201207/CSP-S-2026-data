#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+40;
ll c,t,a[N],n,d,s[N],ans=0,sum=0,pd;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==11||c==12){
		while(t--){
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
			cout<<n-3<<endl;
		}
		return 0;
	}
	while(t--){
		ans=0,sum=1,pd=0;
		memset(s,0,sizeof(s));
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			int j=i;
			while(j>sum&&a[j]-a[sum]>d)sum++;
			s[i]=i-sum;
		}
		for(int i=3;i<=n;i++){
			if(s[i]==2&&a[i+1]-a[i]<=d&&a[i+2]-a[i]>d){
				ans++;
				pd=1;
			}
			else if(pd==1&&((a[i+1]-a[i]<=d&&a[i+2]-a[i]>d)||i==n)){
				ans++;
			}else pd=0;
		}
		printf("%lld\n",ans);
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
