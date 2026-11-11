#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
ll a[500005];
ll sum[500005];
ll res = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1;i <= n; i++) {
    	scanf("%lld",a + i);
	}
    sort(a + 1, a + 1 + n);
    ll tmp=0,res=1;
    ll tot=0;
    for(int i=1;i<n;i++){
    	sum[i]=sum[i-1]+a[i+1]-a[i];
	}
    for(int i = 2;i <= n; i++) {
        tmp+=(++tot)*(a[i]-a[i-1]);
        while(tmp>m){
            tmp-=sum[i-1]-sum[i-tot-1];
            tot--;
        }
        res=max(res,tot + 1ll);
    }
    printf("%lld", res);



    return 0;
}
