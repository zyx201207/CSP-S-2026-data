/*
g++ crystal.cpp -o exe -Wall -O2
./exe
diff crystal.out crystal4.ans

*/
#include<bits/stdc++.h>
using namespace std;
__int128 n,m;
__int128 a[500010],pre[500010];
bool check(int l,int r){
    __int128 sum=pre[r]-pre[l-1];
    if(a[r]*(r-l+1)-sum<=m){
        return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long tn,tm;
    scanf("%lld%lld",&tn,&tm);
    n=tn;m=tm;
    for(int i=1;i<=n;i++){
        long long tmp;
        scanf("%lld",&tmp);
        a[i]=tmp;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int L=1,R=i,res=i;
        while(L<=R){
            int mid=(L+R)>>1;
            if(check(mid,i)){
                res=mid;
                R=mid-1;
            }else{
                L=mid+1;
            }
        }
        ans=max(ans,i-res+1);
    }
    printf("%d\n",ans);
    return 0;
}
