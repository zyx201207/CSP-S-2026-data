#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[500010],c[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,v=0;
    cin>>n>>m;
    int u=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(u--){
        v++;
        for(int i=v;i<=n;i++){
            c[i]++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
