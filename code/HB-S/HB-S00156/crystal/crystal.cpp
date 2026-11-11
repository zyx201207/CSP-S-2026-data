#include<bits/stdc++.h>
using namespace std;
typedef long long li;
#define MAXN 500005
#define MAXM 1000000000000000005l
li a[MAXN];
li n,m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%ld%ld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%ld",&a[i]);
    }
    sort(a,a+n);
    // for(int i=1;i<=n;i++)cerr<<sum[i]<<" ";
    li maxn=INT_MIN;
    for(int i=1;i<=n;i++){
        li sum=0;
        li num=1;
        for(int j=i;j>0;j--){
            li t=(a[i]-a[j])*(i-j);
            if(m-sum>t){
                sum+=t;
                num++;
            }
            else{
                break;
            }
            // sum+=t;
            // num++;
        }
        if(m-sum>=0)
        maxn=max(maxn,num);
    }
    printf("%d",maxn);
    return 0;
}