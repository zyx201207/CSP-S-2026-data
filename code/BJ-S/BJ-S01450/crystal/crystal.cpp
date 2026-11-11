#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,maxx,l=1,r,res;
ll a[N],pre[N],m;
bool Check(int len,int e){
    int h=e-len+1;
    ll res=a[e+1]*len-(pre[e]-pre[h-1]);
    if(res<=m) return true;
    else return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++){
        l=1;r=i-1;res=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(Check(mid,i-1)) res=mid,l=mid+1;
            else r=mid-1;
        }
        maxx=max(maxx,res+1);
    }
    printf("%d",maxx);
    return 0;
}
