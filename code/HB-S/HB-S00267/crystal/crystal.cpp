#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500000],cnt=1,c,m1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    m1=m;
    for(long long i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(long long i=1;i<n;i++){
        for(long long j=1;j<=i;j++){
            if(a[i]-a[i-j]>m) break;
            if(a[i]-a[i-j]<=m){
                m=m-(a[i]-a[i-j]);
                a[i-j]=a[i];
                cnt++;
            }
        }
        if(cnt>c) c=cnt;
        cnt=1;
        m=m1;
    }
    cout<<c;
    return 0;
}
