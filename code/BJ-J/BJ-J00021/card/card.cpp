#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[300005],n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    for(int k=1;k<=n;k++){
    for(int i=k;i<=n;i++){
        b[a[i]]++;
        if(b[a[i]]>1){

        for(int j=1;j<=m;j++){
            b[j]=0;
        }
        b[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        c[i]+=b[i];
        b[i]=0;
    }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i];
    }

    return 0;

}
