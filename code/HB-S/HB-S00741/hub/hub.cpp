#include<bits/stdc++.h>
using namespace std;
int ccc,t;
int n;
int m;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>ccc>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
        }
        cout<<n/m<<"\n";
    }
    return 0;
}