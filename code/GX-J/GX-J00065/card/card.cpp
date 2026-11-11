#include<bits/stdc++.h>
using namespace std;
long long a[10000005],b[500005],c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];

    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=n;j++){
            if(c[a[j]]==0){
                c[a[j]]++;
            }
            else{
                for(int k=j;a[k]!=a[j];k++){
                    c[a[k]]--;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
