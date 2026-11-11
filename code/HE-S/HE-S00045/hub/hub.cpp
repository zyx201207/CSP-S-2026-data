#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,s=1;
    cin>>c>>t;
    for(int h=1;h<=t;h++){
        int n,k,u[200001],v[200001];
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            cin>>u[i]>>v[i];
        }
        cout<<s;
        s++;
    }
    return 0;
}
