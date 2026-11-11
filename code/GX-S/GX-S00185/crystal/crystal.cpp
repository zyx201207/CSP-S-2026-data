#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal1.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long maxx=0,n,m,ans[5000000]={1},w,start=1;
    double a[5000000];
    cin>>n>>m;
    w=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=0,r=n;
    while(l<=r){
        for(int i=(l+r)/2-1;i>=1;i++){
            if(m>=a[(l+r)/2]-a[i]){
               a[i]+=a[i]-a[(l+r)/2];
               ans[start]++;
            }
           m-=a[i]-(l+r)/2;
            if(m==0){
                break;
            }
        }
    l=(l+r)/2+1;
    start++;
    m=w;
    }
    for(int i=1;i<=start;i++){
        if(ans[i]>maxx){
            maxx=ans[i];
        }
    }
    cout<<maxx;
    return 0;
}
