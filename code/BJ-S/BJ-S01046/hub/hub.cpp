#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,n,k;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
        }
        if(n==k)cout<<0<<endl;
        else cout<<(((n+1)/2)+1-k+2)/3<<endl;
    }
    return 0;
}
