#include <bits/stdc++.h>
using namespace std;
long long n,m,l;
long long a[10000005],b[10000005],c[10000005],vis[10000005],v[10000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        l=0;
        for(int j=i;j<=n;j++){
            b[j-i+1]=a[j];
            l++;
        }
        for(int j=1;j<=m;j++)c[j]=0;
        for(int j=1;j<=m;j++)v[j]=0;
        for(int j=1;j<=l;j++){
            if(c[b[j]]){
                bool bl=false;
                for(int k=1;k<j;k++){
                    if(b[k]==b[j]&&(!v[k]))bl=true;
                    if(bl){
                        c[b[k]]=0;
                        v[k]++;
                    }
                }
                c[b[j]]++;
            }
            else{
                c[b[j]]++;
            }
        }
        for(int j=1;j<=m;j++)vis[j]+=c[j];
    }
    for(int i=1;i<=m;i++)cout<<vis[i]<<' ';
    return 0;
}
