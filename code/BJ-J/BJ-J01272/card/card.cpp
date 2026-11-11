#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[200010],c[200010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            b[j]=a[j];
        }
        for(int j=i+1;j<=n;j++){
            for(int k=i;k<j;k++){
                if(b[k]==b[j]){
                    while(k<j)b[k++]=0;
                    break;
                }
            }
        }
        for(int j=i;j<=n;j++)c[b[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<c[i]<<" ";
    return 0;
}

