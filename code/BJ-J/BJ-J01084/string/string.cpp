#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long i0 = 0;
    int n;
    cin>>n;
    string hw = "";
    for(int i=1;i<=n;i++){
        int ai;
        char ci;
        cin>>ai>>ci;
        for(int j=1;j<=ai;j++){
            hw+=ci;
            i0++;
        }
    }
    int ans = 0;
    for(int i=0;i<floor(i0/2.0);i++){
        //cout<<hw[i]<<hw[i0-i-1]<<endl;
        if(hw[i] != hw[i0-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}