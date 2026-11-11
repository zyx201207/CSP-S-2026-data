#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500100],v[300100];
int b[500100],c[300100];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        int tot=0;
        for(int j=i;j<=n;j++){
            if(!c[a[i]]){
                b[++tot]=a[i];
                c[a[i]]=tot;
            }else{
                tot=c[a[i]];
            }
        }
        for(int i=1;i<=tot;i++){
            v[b[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<v[i]<<" ";
    }
}//
