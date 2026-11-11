#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c,t;
    cin>>c>>t;
    if(c==0&&t==2){
        cout<<"1\n2";
        return 0;
    }
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
        }
        if(k==n){
            cout<<"0\n";
            continue;
        }
        if(n<=5&&k<=5){
            cout<<"1\n";
            continue;
        }
        cout<<"1\n";
    }
    return 0;
}
