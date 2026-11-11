#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,sum,pj,jg;
    long long a[500005];
    cin>>n>>m;
    sum=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        sum=sum+a[i];
    }
    sort(a+1,a+n+1);
    pj=sum/n+1;
    for(long long i=1;i<=n;i++){
        if(a[i]<=pj){
            m=m-(pj-a[i]);
            jg++;
        }
    }
    cout<<jg;
    return 0;
}
