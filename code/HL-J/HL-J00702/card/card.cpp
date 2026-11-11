#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,i,j,u;
    cin>>n>>m;
    long long a[n+1],b[m+1]={0},c[n+1],d[m+1]={0};
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            b[a[j]]+=1;
            c[j]=a[j];
            if(b[a[j]]==2){
                b[a[j]]=1;
                for(u=j-1;;u--){
                    if(c[u]==a[j]){
                        c[u]=0;
                        break;
                    }
                    b[c[u]]=0;
                    c[u]=0;
                }
            }

        }
        for(j=1;j<=m;j++){
            if(b[j]!=0){
                d[j]+=1;
                b[j]=0;
            }
        }
    }
    cout<<d[1];
    for(i=2;i<=m;i++){
        cout<<' '<<d[i];
    }
    return 0;
}
