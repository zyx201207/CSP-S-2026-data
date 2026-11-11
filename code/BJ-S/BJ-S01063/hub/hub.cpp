#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t;
int n,k;
int u[N],v[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>c>>t;
    for(int I=1;I<=c;I++){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u[i]>>v[i];
        }
        cout<<u[1]+v[2]<<endl;
    }
    return 0;
}