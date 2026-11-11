#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=-1;
	long long a[500005];
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    	scanf("%lld",a[i]);
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
    	long long cnt=0;
    	long long c=0;
    	while(m>=c){
    		cnt++;
    		if(i-cnt)c=c+a[i]-a[i-cnt];
    		else break;
		}
		ans=max(ans,cnt);
	}
    printf("%lld",ans);
    return 0;
}
