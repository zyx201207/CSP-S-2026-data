#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m;
int hx[N];
int hh[N],ht=0;
int pd[N];
int ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>pd[i];
    }
    for(int i=1;i<=n;i++){
        memset(hh,0,sizeof(hh));
        memset(hx,0,sizeof(hx));
        ht=0;
        for(int j=i;j<=n;j++){
            int id=hx[pd[j]];
            if(id==0||id>ht){
                ht++;
                hh[ht]=pd[j];
                hx[pd[j]]=ht;
            }
            else{
                for(int t=ht;t>=id+1;t--){
                    hx[hh[t]]=0;hh[t]=0;
                }
            }
        }
        for(int j=1;j<=ht;j++){
            ans[hh[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
