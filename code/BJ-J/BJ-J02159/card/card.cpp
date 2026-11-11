#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],c[200005],b[3];
int main(){
    freopen("card.in","w",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[j]==1){
                b[1]=0;
                b[2]=0;
            }
            b[a[j]]=1;
        }
        if(b[1]==1)c[1]++;
        if(b[2]==1)c[2]++;
    }
    cout<<c[1]<<' '<<c[2];
    return 0;
}
