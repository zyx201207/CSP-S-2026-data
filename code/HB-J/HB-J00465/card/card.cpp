#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,t=0;
int a[500010],st[500010],c[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        int f=1,id=0;
        for(j=t;j>=0 && f;j--){
            if(st[j]==a[i]){
                f=0;
                id=j;
            }
        }
        if(f){
            st[t++]=a[i];
        }
        else{
            t=id;
            st[t++]=a[i];
        }
        bool b[500010];
        memset(b,0,sizeof(b));
        for(j=0;j<t;j++){
            if(!b[st[j]]){
                b[st[j]]=1;
                c[st[j]]++;
            }
        }
    }
    for(i=1;i<=m;i++){
        cout<<c[m]<<" ";
    }
    return 0;
}
