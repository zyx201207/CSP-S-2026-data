#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005],d[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        int v=1;
        for(int j=i;j<=n;j++){
            b[a[j]]++;
            if(b[a[j]]==1){
                d[v]=a[j];
                c[a[j]]=v;
                v++;
            }else{
                v=c[a[j]];
                b[a[j]]=1;
            }
        }
        for(int w=i;w<=n;w++){
            d[i]+=b[i];
        }
    }
    for(int i=1;i<=m;i++)cout<<d[i]<<endl;






    return 0;
}
