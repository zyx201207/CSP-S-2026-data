
#include<bits/stdc++.h>
using namespace std;
int a[500010];
int ans[300010];
int main(){
    freopen("card5.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(ans,0,sizeof(ans));
    int pos[300010];
    int game[300010],h;
    for(int i=1;i<=n;i++){
        h=1;
        memset(pos,0,sizeof(pos));
        for(int j=i;j<=n;j++){
            if(pos[a[j]]){
                for(int k=pos[a[j]]+1;k<h;k++){
                    pos[game[k]]=0;
                }
                h=pos[a[j]]+1;
            }
            else{
                pos[a[j]]=h;
                game[h]=a[j];
                h++;
            }
        }
        for(int j=1;j<h;j++){
            ans[game[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
