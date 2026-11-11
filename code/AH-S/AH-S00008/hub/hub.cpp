#include<bits/stdc++.h>
using namespace std;
int n,k,c,t;
void solve(){
    cin>>n>>k;
    for(int i=1,u,v;i<=n;i++){
        cin>>u>>v;
    }
    if(c==13||c==14){
        int m=n/2+1;
        if(k>=m)cout<<"1\n";
        else cout<<(m-k+1)/2+1<<"\n";
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)solve(t);
}
