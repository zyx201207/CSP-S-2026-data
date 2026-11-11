#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+10;
ll n,m,a[MAXN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll p=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[j]>i) cout<<j-1;
        }
    }
    return 0;
}
