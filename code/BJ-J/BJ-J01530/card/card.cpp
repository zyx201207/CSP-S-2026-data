#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,f,a[500100],last[300100],tim[300100],vis,t,x,ans[300100];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=n;i>=1;i--){
        cin>>a[i];
        if(a[i]<a[i-1]){
            f=1;
        }
    }
    if(f==1){
        for(int i=1;i<=n;i++){
            ans[a[i]]=max(ans[a[i]],n-i+1);
        }
    }else{
        t=INT_MAX;
        for(int i=1;i<=n;i++){
            if(last[a[i]]==0 or (last[a[i]]>t and tim[a[i]]<x)){
                last[a[i]]=++vis;
                tim[a[i]]=i;
                a[vis]=a[i];
            }else{
                vis=last[a[i]];
                t=vis;
                x=i;
            }
            for(int j=1;j<=vis;j++){\
                ans[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//26263232606606
//Im big chuanzi
//kskbl zdjd
//^q^
//ztz mqc 99
//cym gzy 99
//gz gyr 99
//cx99
//Track||Chick!
//woshizhapianfan
//woyaoshangqipaxingweidashang
//pinjinquanliwufazhanshengT4
