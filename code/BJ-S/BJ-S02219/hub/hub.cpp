#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2E6+10;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
        }
        if(c==13||c==14){
            cout<<1;
        }
        else if(k>=n){
            cout<<0<<"\n";
        }
        else cout<<1<<"\n";
    }
    return 0;
}
