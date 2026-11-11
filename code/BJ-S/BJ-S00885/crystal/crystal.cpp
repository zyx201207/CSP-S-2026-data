#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long lis[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&lis[i]);
    }
    sort(lis+1,lis+1+n);
    long long cnt=1,us=0;
    for(long long i=2;i<=n;i++){
        if((lis[i]-lis[i-1])*(i-1)+us<=m){
            us+=(lis[i]-lis[i-1])*(i-1);
            cnt++;
        }
        else break;
    }
    printf("%lld",cnt);
    return 0;
}
