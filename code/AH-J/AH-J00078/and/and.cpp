#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200000+10];
long long f(long long x,long long cnt){
	if(cnt>=m)return 2147483647;
	if(x>n)return 0;
	return max(f(x+1,cnt+1)&a[x],f(x+1,cnt));
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    printf("%lld",f(1,0));
    return 0;
} 
