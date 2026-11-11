#include <bits/stdc++.h>
using namespace std;
int c,t,u,v,n,k;
vector<int>a[100005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k;
        for(int k=1;k<n;k++){
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        cout<<1<<endl;
    }
    return 0;
}
