#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    freopen("card1.in","r",stdin);
    freopen("card1.out","w",stdout);
    cin>>n>>m;
    bool ft=true;
    int a[100005],b[100005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=i;j++){
            if(a[i]==a[j]&&!ft) for(int l=1;l<=1;l++){
                b[i]=a[l];
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    return 0;
}
