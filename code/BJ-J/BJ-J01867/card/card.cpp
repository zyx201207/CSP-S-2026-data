#include<bits/stdc++.h>
using namespace std;
long long cnt[300005],n,m,a[500005],pd[500005],pos[300005],h;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        h=0;
        memset(pos+1,0,sizeof(pos));
        memset(pd+1,0,sizeof(pd));
        for(int j=i;j<=n;j++){
            int x=a[j];
            if(pos[x]){
                for(int k=pos[x]+1;k<=h;k++){
                    pos[pd[k]]=0;
                    pd[k]=0;
                }
                h=pos[x]-1;
                pos[x]=0;
            }else{
                h++;
                pos[x]=h;
                pd[h]=x;
            }
        }
        for(int j=1;j<=h;j++){cnt[pd[j]]++;}
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
