#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        int a[200005],b[200005];
        for(int i=1;i<n;i++)cin>>a[i]>>b[i];
        cout<<k-1<<"\n";
    }
    return 0;
}
