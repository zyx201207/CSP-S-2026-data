#include<bits/stdc++.h>
using namespace std;
int c[500005],d[300005];
int main(){
    freopen("card.in","r",stdin);
    int n,m,a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
        bool b=false;
        int k=0;
            for(int k=i;k<=n;k++){
                if(a[j]==a[k]){
                    b=true;
                    break;
                }
            }
        }if(b){
            for(int i=k;i<=n;i++)c[i]=0;
        }c[i]=a[i];
    }for(int i=1;i<=n;i++){
        d[c[i]]++;
    }for(int i=1;i<=m;i++){
        cout<<d[i];
    }
    return 0;
}
