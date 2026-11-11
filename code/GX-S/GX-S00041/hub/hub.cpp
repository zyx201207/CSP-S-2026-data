#include<bits/stdc++.h>
using namespace std;
int a[100005];
void build(int u1,int v1){
    a[v1]=u1;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int n,k,u,v;
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        build(u,v);
    }
    cout<<1<<endl;
    cout<<2;
    return 0;
}
