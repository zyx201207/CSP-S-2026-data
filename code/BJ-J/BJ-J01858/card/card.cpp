#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[1000010],cun[10010],zt[10010],tong[100010],jia[10010],m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        memset(cun,0,sizeof(cun));
        memset(zt,0,sizeof(zt));
        for(ll j=i;j<=n;j++){
            if(cun[a[j]]){
                for(ll k=cun[a[j]];k<j;k++){
                    zt[k]=1;
                    if(cun[a[k]]==k){
                        cun[a[k]]=0;
                    }
                }
            }
            cun[a[j]]=j;
        }
        memset(jia,0,sizeof(jia));
        for(ll j=i;j<=n;j++){
            if(zt[j])continue;
//            cout<<j<<' ';
            if(!jia[a[j]]){
                tong[a[j]]++;
            }
            jia[a[j]]=1;
        }
//        cout<<endl;
    }
    for(ll i=1;i<=m;i++){
        cout<<tong[i]<<' ';
    }
    return 0;
}
