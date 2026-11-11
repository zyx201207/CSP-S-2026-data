#include<bits/stdc++.h>
using namespace std;
long long a[6000000]={-3,-1,2,2,7},b[6000000],c[6000000];
long long n,m;
int ch(long long x){
    long long mi=1e9;
    for(int i=1;i<=n-x+1;i++){
        long long q=c[i+x-1]-c[i-1];
        mi=min(q,mi);
    }
    if(mi>m)return 1;
    else if(mi==m)return 0;
    else return 2;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        b[i]=abs(a[i]-a[i-1]);
    }
    sort(b+1,b+n+1);
    for(int i=2;i<=n;i++){
        c[i]=c[i-1]+b[i];
    }
    long long l=1,r=n;
    while(l<=r){
        long long mid=(l+r)/2;
        if(ch(mid)==1)r=mid-1;
        else if(ch(mid)==2)l=mid;
        else {
            cout<<mid;
            return 0;
        }
    }
    cout<<l;
    return 0;
}
