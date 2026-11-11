#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans[300005],c[300005];
bool flag=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&a[i]>a[i-1]) flag=0;
    }
    if(flag){
        for(int i=1;i<=n;i++) ans[a[i]]=i;
    }
    else{
        for(int i=1;i<=n;i++){
            ll xb=0;
            for(int j=i;j<=n;j++){
                bool pd=0;
                ll nx;
                for(int k=1;k<=xb;k++){
                    if(c[k]==a[j]){
                        pd=1;
                        nx=k;
                        break;
                    }
                }
                if(pd) xb=nx;
                else c[++xb]=a[j];
            }
            for(int j=1;j<=xb;j++) ans[c[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
