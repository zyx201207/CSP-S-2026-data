#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int minn=0x3f3f3f3f;
        for(int i=1,x,y;i<=n;i++){
            cin>>x>>y;
            minn=min(minn,min(x,y));
        }
        cout<<minn<<endl;
    }
    return 0;
}
