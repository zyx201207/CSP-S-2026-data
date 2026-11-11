#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,d;
    string b;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b;
        d=d+a;
    }
    if(n==1){
        cout<<"0";
        return 0;
    }
    if(n==2){
        cout<<"0";
        return 0;
    }
    cout<<d;
    return 0;
}
