#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,mx=-1000000001,mxl=0,f;
    cin>>n>>m;
    long long a[1000005];
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=mx){
            mx=a[i];
            mxl=i;
        }
    }
    for(int i=m;i>=1;i--){
        f=0;
        for(long long j=1;j<=n;j++){
            if(a[mxl-j]<a[mxl]&f==0){
                a[mxl-j]++;
                f=1;
            }
        }
    }
    int cnt=0;
    for(long long i=1;i<=n;i++){
        if(a[i]==mx){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
