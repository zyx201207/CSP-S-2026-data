
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a[10005],b[10005];
    long long maxn=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=1;
    for(int i=0;i<10;i++){
        string e,r,t,y;
        b[i]=a[i];
        for(int p=0;p<=10;p++){
            e+=b[p]%2;
            b[p]/2;
        }
        for(int l=10;l>=0;l--){
              for(int j=0;j<=10;j++){
                e[i]=r[i];
        }}

        b[i]=a[i+cnt];
        for(int h=0;h<=10;h++){
            t+=b[i+cnt]%2;
            b[i+cnt]/2;
        }
       for(int g=10;g>=0;g--){
              for(int j=0;j<=10;j++){
                t[i]=y[i];
        }}
        maxn=e[i] and a[i+cnt];
        cnt++;
    }
    cout<<maxn;
    }
