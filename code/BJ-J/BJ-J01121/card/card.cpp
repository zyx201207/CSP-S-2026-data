#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int vis[500004];
int a[500004];
int f[500005];
int ans[500004];


void show(){

    for(int i=1;i<=n;i++){

        cout<<vis[i]<<" ";
    }
    cout<<endl;
}

signed main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    /*

    cout<<n<<" "<<m<<endl;

    for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";

    }
*/

    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));

        memset(f,0,sizeof(f));
        //show();
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                for(int k=f[a[j]];k<=j;k++){
                    vis[a[k]]=0;
                }
                vis[a[j]]=1;
            }else{
                vis[a[j]]=1;
                if(!f[a[j]]) f[a[j]]=j;
            }
            //cout<<j<<" ";
        }
        //cout<<endl;
        for(int j=1;j<=m;j++){
            if(vis[j]) ans[j]++;
        }


    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
