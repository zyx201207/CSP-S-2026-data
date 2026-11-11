#include<bits/stdc++.h>
using namespace std;
int a[500005],c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    int d[n+1]{0};
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++)
            d[j]=a[j];
        for(int j=1; j<=n; j++){
            for(int l=j+1; l<=n; l++){
                if(d[l]==d[j]){
                    int b=l-j;
                    while(b--)
                        d[j+b]=0;
                }
            }
            if(d[j]==i)
                c[i]++;
        }
    }
    for(int i=1; i<=m; i++)
        cout<<c[i]<<" ";
    return 0;
}

