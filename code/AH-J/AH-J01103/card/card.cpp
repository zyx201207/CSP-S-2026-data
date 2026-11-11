#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[300010][3],c[300010],d[300010];
void f(int i){
    int j,k=i;
    for(;i<=n;i++){
        if(b[a[i]][1])
            for(j=b[a[i]][2];j<=i;j++)b[a[j]][1]=0;
        b[a[i]][1]=1;
        b[a[i]][2]=i;
    }
    for(j=k;j<=n;j++){
        if(b[a[j]][1] && !d[a[j]]){
                c[a[j]]++;
                d[a[j]]=1;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        memset(d,0,sizeof(d));
        f(i);
    }
    for(i=1;i<=m;i++)cout<<c[i]<<' ';
}
