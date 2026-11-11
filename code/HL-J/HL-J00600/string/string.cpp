#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    char b[n+1]="/0";
    long long num=0;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a>>b[i];
        num+=a;
    }
    int m=0;
    for(int i=2;i<=n;i++){
        if(b[i]-b[i-1]==0){
            m++;
        }
    }
    if(m+1==n){
        cout<<0;
        return 0;
    }
    cout<<num/2;

    return 0;
}
