#include<bits/stdc++.h>
using namespace std;
const long long r=100000000000;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;char c;char t[r];long long a,_29sumgpc=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;cin>>c;
        for(int j=1;j<=a;j++){
            _29sumgpc++;
            t[_29sumgpc]=c;

        }
    }
    for(int i=1;i<=_29sumgpc/2+1;i++){
        if(t[i]!=t[_29sumgpc-i+1])cnt++;
    }cout<<cnt;
    return 0;
}

