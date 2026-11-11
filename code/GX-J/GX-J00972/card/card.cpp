#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005]={};
    int tongji[500005]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int g=1,b[500005]={},c[500005]={};
        for(int j=i;j<=n;j++){
            if(c[a[j]]!=0&&g>=c[a[j]]) g=c[a[j]];
            else if(c[a[j]]==0)c[a[j]]=g;
            else c[a[j]]=0;
            b[g++]=a[j];
        }
        g--;
        for(int i=1;i<=g;i++){
            tongji[b[i]]++;
            cout<<b[i]<<" ";
        }
        cout<<"\n";
    }
    for(int i=1;i<=m;i++) cout<<tongji[i]<<" ";
    return 0;
}
