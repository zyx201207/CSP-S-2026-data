#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn,a[500005];
bool flag1=1,flag2=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)flag1=0;
    }
    long long d=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=d){
            flag2=0;
            break;
        }
    }
    if(flag1){
        int id=0;
        for(int i=1;i<=n;i++){
            long long k=i*(i+1)/2;
            id=i;
            if(k>m)break;
        }
        cout<<id;
        return 0;
    }
    if(flag2){
        int id=0;
        for(int i=1;i<=n;i++){
            long long k=i*(i+1)/2*d;
            id=i;
            if(k>m)break;
        }
        cout<<id;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        long long cnt=0,ans=0;
        for(int j=i;j>=1;j--){
            ans+=(a[i]-a[j]);
            if(ans<=m)cnt++;
            else break;
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
return 0;
}
