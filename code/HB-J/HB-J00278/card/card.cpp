#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],pos[300005],mp[300005],t[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        int tot=0;
        memset(pos,0,sizeof pos);
        memset(mp,0,sizeof mp);
        for(int i=l;i<=n;i++){
            if(pos[a[i]]==0||pos[a[i]]>tot){
                pos[a[i]]=++tot;
                mp[tot]=a[i];
            }
            else{
                tot=pos[a[i]];
            }
        }
        for(int i=1;i<=tot;i++){
            t[mp[i]]++;
//            cout<<mp[i]<<' ';
        }
//        cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<' ';
    }
    return 0;
}
