#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int q,h;
    for(int i=1;i<n;i++){
        c[i]=a[i+1]-a[i];
        h+=c[i];
    }
    for(int i=1;i<(n+1)/2;i++) q+=c[i];
    if(q<=h-q){
        for(int i=(n+1)/2;i>=1;i--){
            if(m<=0) break;
            m-=(a[(n+1)/2]-a[i]);
            a[i]=a[(n+1)/2];

        }
    }else{
        for(int i=n;i>=(n+1)/2;i--){
            if(m<=0) break;
            m-=(a[(n+1)/2]-a[i]);
            a[i]=a[(n+1)/2];

        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[(n+1)/2]) cnt++;
    }
    cout<<cnt;
    return 0;
}
