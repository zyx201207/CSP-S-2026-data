#include<bits/stdc++.h>
using namespace std;
int n,m,sz,fro,sum,ans,pt;
struct xxs{
    int nxt,x,q;
}a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].x);
        a[i].nxt=i+1;
        a[i].q=i-1;
    }
    a[n].nxt=0;
    a[1].q=0;
    fro=1;
    sz=n;
    for(int i=29;i>=0;i--){
        sum=0;
        for(int j=1,k=fro;j<=sz;j++,k=a[k].nxt){
            if(a[k].x&(1<<i)){
                sum++;
            }
        }
        if(sum>=m){
            ans+=(1<<i);
            pt=sz;
            for(int j=1,k=fro;j<=pt;j++){
                if((a[k].x&(1<<i))==0){
                    sz--;
                    if(k==fro){
                        fro=a[k].nxt;
                    }
                    else{
                        a[a[k].q].nxt=a[k].nxt;
                        a[a[k].nxt].q=a[k].q;
                    }
                }
                k=a[k].nxt;
            }
        }
    }
    printf("%d",ans);
    return 0;
}