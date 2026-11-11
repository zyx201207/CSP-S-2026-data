#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c[500005];
ll b[500005];
ll a[500005];
ll n,m;
vector<ll>p[500005];
ll s[500005];
ll vis[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=b[a[i]];
        b[a[i]]=i;
        //cout<<c[i]<<" ";
    }
    //cout<<endl;
    for(int i=1;i<=n;i++){
        if(b[a[i]]==i){
            p[i].push_back(i+1);
            //cout<<i+1<<" "<<i<<endl;
        }
        if(c[i]!=0){
            p[c[i]].push_back(i);
            //cout<<i<<" "<<c[i]<<endl;
        }
    }
    /*for(int i=1;i<=n+1;i++){
        for(int j=0;j<p[i].size();j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++){
        s[p[i][0]]+=(1+s[i]);
    }
    /*for(int i=1;i<=n+1;i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;*/
    for(int i=1;i<=m;i++){
        cout<<s[b[i]]+1<<" ";
    }
    cout<<endl;
    return 0;
}
