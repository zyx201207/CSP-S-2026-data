#include <bits/stdc++.h>
using namespace std;
const int R=1e5*5+5;
struct s{
    long long int pre;
    int uid;
}hfr[R];
int n;
long long int m,arr[R],ans;
bool cmp(s a,s b){
    return a.pre>b.pre;
}
long long int check(int x){
    long long int cnt=0,k=0;
    int l=x;
    while (k+(arr[x]-arr[l])<=m and l>=1){
        k+=arr[x]-arr[l];
        cnt++;
		
        l--;
    }
    return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;++i)
        scanf("%lld",&arr[i]);
    sort(arr+1,arr+1+n);
    for (int i=1;i<=n;++i){
        hfr[i].uid=i;
        hfr[i].pre=arr[i]-arr[i-1];
    }
    sort(hfr+1,hfr+1+n,cmp);
    printf("%lld ",check(hfr[1].uid));
    for (int i=1;i<=n;++i){
        ans=max(ans,check(hfr[i].uid));
    }
    printf("%lld",ans);
	return 0;
}

