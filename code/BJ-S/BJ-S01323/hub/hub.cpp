#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>c>>c;
        }
        cout<<ceil(double((n+1)/2+1-k)/4)<<endl;
    }
    return 0;
}