#include<bits/stdc++.h>
using namespace std;
long long a[500010],qi[500010];
int n,m,maxx=1,cnt=0,te=1;
int er(int l,int r,long long x,int y){
    while(l<r){
        int mid=l+r>>1;
        if(x<mid*a[y]-qi[y-1]+qi[y-mid-1]) r=mid;
        else l=mid+1;
    }
    return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) qi[i]=qi[i-1]+a[i];
    for(int i=2;i<=n;i++){
        cnt=0;
        int x=er(1,i-1,m,i);
        if(x<=i-1) maxx=max(maxx,x+1);
    }
    cout<<maxx;
    return 0;
}
