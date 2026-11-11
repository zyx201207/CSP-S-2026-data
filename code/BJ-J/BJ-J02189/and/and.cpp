#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN],aq[MAXN];
ll n,m;
bool k[MAXN][64];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        aq[i]=a[i];
        int p=floor(log2(aq[i]));
        for(int tp=1;aq[i]!=0;tp++){
            k[i][tp]=aq[i]%2;
            aq[i]/=2;
        }
    }
    bool avlb[MAXN]={};
    for(int i=1;i<=n;i++) avlb[i]=1;
    for(int j=31;j>=0;j--){
        ll ppct=0;
        bool flg[MAXN]={};
        for(int i=1;i<=n;i++){
            if(k[i][j]&&avlb[i]){
                ppct++;
                flg[i]=1;
            }
        }
        if(ppct==m){
            ll q=1;
            q<<=40;
            q--;
            for(int i=1;i<=n;i++){
                if(flg[i]) q&=a[i];
            }
            cout<<q;
            return 0;
        }else if(ppct>m){
            for(int i=1;i<=n;i++){
                if(!flg[i]) avlb[i]=0;
            }
        }
        if(j==0){
            ll tmp=0;
            ll q=1;
            q<<=40;
            q--;
            for(int i=1;i<=n;i++){
                if(avlb[i]&&tmp<=m) q&=a[i];
                tmp++;
            }
            cout<<q;
        }
    }
    return 0;
}
