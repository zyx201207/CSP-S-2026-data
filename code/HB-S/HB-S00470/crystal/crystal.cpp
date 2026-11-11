#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500010];
long long s[500010];
bool check(int mid){
    for (int l=1;l+mid-1<=n;l++){
        int r=l+mid-1;
        long long cha=a[r]*(mid-1)-(s[r-1]-s[l-1]);
        if (cha<=m)return 1;
    }
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    s[0]=0;
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l=1,r=n,mid,best=-1;
    while (l<=r){
        mid=(l+r)>>1;
        if (check(mid)){
            l=mid+1;
            best=mid;
        }
        else{
            r=mid-1;
        }
    }
    printf("%lld",best);
    return 0;
}
/*100AC*/
