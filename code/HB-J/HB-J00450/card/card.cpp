#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m;
int a[500100];
int q[500100],t=0;
bool b[500100];
int ans[500100];
bool u=1;
int bk[500100];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i-1]>a[i]){
            u=0;
        }
        bk[a[i]]=i;
    }
    if(u==1){
        for(int i=1;i<=n;i++){
            cout<<bk[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        t=0;
        for(int j=i;j<=n;j++){
            if(b[a[j]]!=0){
                while(t!=0&&q[t]!=a[j]){
                    b[q[t]]=0;
                    t--;
                }
                continue;
            }
            b[a[j]]=1;
            q[++t]=a[j];
        }
        for(int j=1;j<=m;j++){
            ans[j]+=b[j];
            b[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
