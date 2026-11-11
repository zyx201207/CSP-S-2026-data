#include<bits/stdc++.h>
using namespace std;

const int N=500005;

long long a[N],n,m,l,r,midd,sum;

bool check(){
    long long sum=0;
    for(int i=1;i<=midd;i++){
        sum+=a[midd]-a[i];
    }
    for(int i=midd;i<=n;i++){
        if(sum<=m)return 1;
        sum=sum+a[i-midd+1]-a[i+1]+midd*(a[i+1]-a[i]);
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    l=1,r=n;
    while(l<=r){
        midd=(l+r)/2;
        if(check())l=midd+1;
        else r=midd-1;
    }
    cout<<r;
}


