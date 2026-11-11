#include<iostream>
#include<cstring>
using namespace std;
int a,b,c[500005],vis[500005],f[500005],fl[500005],cnt[500005];
void d(int x){
    memset(fl,0,sizeof(fl));
    memset(f,0,sizeof(f));
    memset(vis,0,sizeof(vis));
    for(int n=x;n<=a;n++){
        if(f[c[n]]!=0&&!vis[f[c[n]]]){
            for(int m=f[c[n]];m<n;m++){
                vis[m]=1;
            }
        }
        f[c[n]]=n;
    }
    for(int m=x;m<=a;m++){
        if(!vis[m]){
            fl[c[m]]=1;
        }
    }
    for(int m=1;m<=b;m++){
        cnt[m]+=fl[m];
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>a>>b;
    for(int n=1,x;n<=a;n++){
        cin>>c[n];

    }
    for(int n=1;n<=a;n++)d(n);
    for(int m=1;m<=b;m++){
        cout<<cnt[m]<<" ";
    }
    return 0;
}
