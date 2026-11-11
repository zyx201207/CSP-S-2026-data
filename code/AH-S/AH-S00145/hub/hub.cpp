#include<bits/stdc++.h>
using namespace std;
int u[4005],v[4005],h=1;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c,t;
    while(t--){
        int n,k;
        for(int i=1;i<=n;i++){
            cin>>u[i]>>v[i];
        }
        cout<<h<<endl;
        h++;
    }
    return 0;
}
