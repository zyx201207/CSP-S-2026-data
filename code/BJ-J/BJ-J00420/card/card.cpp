#include<bits/stdc++.h>
using namespace std;
int n,m,a[514114],ans[514114],tans[514114],v[414114],ttans[514114];
bool fu=1,fl=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        if(a[i]>a[i-1]&&i!=1) fl=0;
        if(a[i]<a[i-1]) fu=0;
    }
    if(fl||fu){
        for(int i=1;i<=n;i++){
            ans[a[i]]=i;
        }
    }
    else{
        int x=1;
        for(int i=1;i<n;i++){
            for(int j=i;j<=n;j++,x++){
                if(v[a[j]]) x=v[a[j]];
                else{tans[x]=a[j];v[a[j]]=x;}
            }
        for(int j=1;j<=x;j++) ans[tans[j]]++;
        if(x==n-i+2){
            for(int j=i+1,k=1;j<=n;j++,k++) ttans[a[j]]=k;
            for(int j=1;j<=m;j++) ans[j]+=ttans[j];
            break;
        }
        memset(v,0,sizeof v);
        }
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}
