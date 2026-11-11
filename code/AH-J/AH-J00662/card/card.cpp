#include<bits/stdc++.h>
using namespace std;
int a[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1)cout<<n;
    if(m==2){
            int k=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1])k=i;
        }
    cout<<k<<' '<<n-k;
    }

return 0;
}
