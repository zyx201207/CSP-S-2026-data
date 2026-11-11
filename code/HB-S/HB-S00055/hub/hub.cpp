#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pi3 pair<int,pii>
int lowbit(int x){
    return x&-x;
}
ll c,t,n,m;
int main(){
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for (int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            // edge[u].push_back(v);
            // edge[v].push_back(v);
        }
        if(n==m){
            cout<<0<<endl;
            continue;
        }
        ll p=(n-1)/2;
        if(m>p){
            cout<<1<<endl;
        }
        else{
            p++;
            ll cnt=0;
            if(p%2==1){
                p--;
                m--;
                // cnt++;
            }
            cnt+=m/2;
            p/=2;
            p-=cnt;
            cout<<p+1<<endl;
        }
    }
    return 0;
}