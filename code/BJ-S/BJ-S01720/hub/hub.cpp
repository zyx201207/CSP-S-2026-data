#include <bits/stdc++.h>
using namespace std;
int x[1000005];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d;cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(n&1) cout<<d/2+1;
        else cout<<(d+1)/2;
    }
    return 0;
}
