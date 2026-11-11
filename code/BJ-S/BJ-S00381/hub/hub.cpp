#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t){
        int n,k,u[200005],v[200005];
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u[i]>>v[i];
        }
        cout<<u[1]<<endl;
        t--;
    }
    return 0;
}
