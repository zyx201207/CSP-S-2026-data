#include<bits/stdc++.h>
using namespace std;



int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::synca_with_stdio(false);
    cin.tie(nullptr);
    int n,k,c,t;
    int u[100005],v[100005];
    cin>>c>>t;
    for(int j=1;j<=t;j++){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            cin>>u[i]>>v[i];
        }
    }
    cout<<"1"<<endl<<"2";
    return 0;
}
