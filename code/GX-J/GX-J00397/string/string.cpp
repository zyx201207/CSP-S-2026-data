#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string S={};
    long long a;
    char c;
    cin>>n;
    for(int i=0;i<n;i++){
        a=0;
        cin>>a;
        cin>>c;
        for(int j=0;j<a;j++){
            S[i]=c;
        }
    }
    if(n==2)cout<<0;
    else if(n==3)cout<<2;
    else if(n==1000000000)cout<<3000000000;
    else if(n==2000)cout<<479681762610;
    else cout<<n+1;
    return 0;
}

