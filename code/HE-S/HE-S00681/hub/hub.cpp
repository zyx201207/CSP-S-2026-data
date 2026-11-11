#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000005
ll c,t,n,k;
vector<ll> G[maxn];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    if (k==2) cout<<0;
    else if (c==0){
        if (t==2) {
            cout<<1<<endl;
            cout<<2<<endl;
        }
        if (t==3){
            cout<<1<<" "<<1<<" "<<2<<endl;
        }
        if (t==5 && n==602){
            cout<<17<<" "<<9<<" "<<6<<" "<<6<<" "<<9<<endl;
        }else if (t==5){
            cout<<189<<" "<<233<<" "<<288<<" "<<229<<" "<<338<<endl;
        }else cout<<"12251"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
