#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
typedef long long ll;
ll n,m,a[N],sum,ans=0;
string c1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=m;i++){
        cout<<a[n-i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
