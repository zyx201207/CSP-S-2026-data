#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
typedef long long ll;
ll n,m,a[N],sum,ans=0;
string c1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[n- 2];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
