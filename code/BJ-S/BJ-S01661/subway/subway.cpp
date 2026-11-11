#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,n,m,d,q;
ll a[505][500005];
ll t[505][500005];
ll ways[20005][20005];
ll vis[20005][20005];
ll searching(ll s,ll e){
    ll mintime =0;
    if(s==e) return mintime;
    for(int i=1;i<=m;i++){
        if(ways[s][i]!=0&&vis[s][i]=0){
            vis[s][i]=1;
            
            mintime=min(mintime,searching(i,e)));


        }


    }



}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;

    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        int k;
        cin>>k;
        ll st=0;
        for(ll j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];

            if(st!=0)
                way[st][a[i][j]]++;
            st=a[i][j];

        }

    }
    while(q--){
        memset(vis,0,sizeof(vis));
        memset(ways,0,sizeof(ways));
        ll x,y;
        cin>>x,y;
        cout<<searching(x,y)<<endl;












    }





    return 0;
}

