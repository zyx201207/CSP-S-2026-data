#include<bits/stdc++.h>
using namespace std;
long long int m,n;
int a[500005],b[300005],c[300005],pd[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int j=1;j<=n;j++){
        cin>>a[j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                c[j]=0;
        }
        for(int j=1;j<=n;j++){
                pd[j]=0;
        }
        for(int j=i;j<=n;j++){
            if(c[a[j]]!=0&&pd[c[a[j]]]==0){
                for(int z=c[a[j]];z<j;z++){
                    pd[z]=1;
                }
            }
            c[a[j]]=j;
        }
        for(int j=1;j<=m;j++){
            if(pd[c[j]]==0&&c[j]!=0){
                b[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
