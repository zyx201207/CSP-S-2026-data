#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N];
int s[N];
bool check(int v){
   for(int i=1;i+v-1<=n;i++){
        int j=i+v-1;
        int c=s[j]-s[i-1];
        int k=a[j]*v*1LL;
        if(k-c<=m){
            return true;
        }
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l=1,r=n,mid;
    int ans=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    printf("%lld",l-1);
    return 0;
}
