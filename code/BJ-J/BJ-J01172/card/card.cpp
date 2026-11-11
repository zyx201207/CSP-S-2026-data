#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],cz[505],cnt[5005];
int main(){
        freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int ok[505];
        memset(ok,0,sizeof ok);
        //memset(cnt,0,sizeof cnt);
        int fi=i;
        for(int j=i;j<=n;j++){
            if(!ok[a[j]]){
                ok[a[j]]=j;
            }
            else{
                for(int x=i;x<=j;x++) ok[a[x]]=0;
                fi=j;
                ok[a[j]]=j;
            }
        }
        for(int j=fi;j<=n;j++){
            cnt[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
}
