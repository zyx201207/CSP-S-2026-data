#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[500010],a[500010],t[500010],q[100010][3],ans=INT_MAX;
void dfs(x,y,s){
    for(int i=1;i<=n;i++,h){
        if(i[1]==y){s+=t[i],dfs(i[1],y,s,h)}
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++){
        cin>>k;
        for(ll j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
    }
    for(ll i=1;i<=q;i++){
        cin>>q[i][1]>>q[i][2];
        q[i][0]=dfs(q[i][1],q[i][2],0,i)+w[q[i][1]]+w[q[i][2]];
    }
    for(ll i=1;i<=q;i++)cout<<q[i][0]<<endl;
    return 0;
}
