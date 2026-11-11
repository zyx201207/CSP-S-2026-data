#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int st[200005];
int tl=0,x[200005];
int t[200005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(st,0x3f,sizeof st);
        tl=0;
        for(int j=i;j<=n;j++){
            if(st[a[j]]<=tl&&x[st[a[j]]]==a[j]) tl=st[a[j]];
            else{
                tl++;
                st[a[j]]=tl;
                x[tl]=a[j];
            }
        }
        for(int j=1;j<=tl;j++) t[x[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<t[i]<<" ";
    return 0;
}
