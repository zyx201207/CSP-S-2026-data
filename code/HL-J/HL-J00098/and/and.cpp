#include<bits/stdc++.h>
using namespace std;
long long sz[200000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>sz[i];
    }
    long long z,mj=0;;
    long long maxnn=-1000
;    for(int i=1;i<=n;i++){
        z=sz[i];
        for(int j=i+1;j<=n;j++){

            if(mj==m) break;
            z=z&sz[j];
            mj++;
        }
        mj=0;
        maxnn=max(maxnn,z);
        z=0;
    }
    cout<<maxnn;
    return 0;
}       `
