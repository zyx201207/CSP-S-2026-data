#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[1000000+10];

bool check(int x){
    int mid=x/2+1,le=1,ri=x;
    long long ans=0;
    for(int i=1;i<=x;i++)ans+=a[ri]-a[i];

    if(ans<=m)return 1;
    while(ri<n){
        ans-=a[ri]-a[le];
        ans+=(a[ri+1]-a[ri])*(x-1);
        le++,ri++,mid++;
        if(ans<=m)return 1;
    }
    if(ans<=m)return 1;
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+1+n);
    //for(int i=1;i<=n;i++)cout << a[i]<<' ';
    int ans=0;
    int le=0,ri=n;
    while(le<=ri){
        int mid=(le+ri)/2;
        if(check(mid))ans=max(ans,mid),le=mid+1;
        else ri=mid-1;
    }cout << ans;
    return 0;
}
/*
wocaonimaweishenmebunengdazhongwena!!!
*/
