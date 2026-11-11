#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
bool check(int mid){
    long long tmp = m;
    for(int i = 1;i <= mid - 1;i++){
        tmp = tmp - (a[mid] - a[i]);
        //printf("i=%d tmp=%d a=%d,%d\n",i,tmp,a[mid],a[i]);
        if(tmp < 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a + 1,a + n + 1);
    int l = 1,r = n;
    int ans;
    while(l <= r){
        int mid = (l + r) / 2;
        //printf("mid = %d\n",mid);
        if(check(mid)){
   //         printf("mid2 = %d\n",mid);
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    printf("%d",ans);
    return 0;
}

