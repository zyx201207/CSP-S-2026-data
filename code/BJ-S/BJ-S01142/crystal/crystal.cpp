#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
int n;
ll a[maxn],cz[maxn],m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll zws=a[n/2+1];
    for(int i=1;i<=n;i++){
        cz[i]=abs(zws-a[i]);
    }
    for(int i=1;i<=n;i++){
        if(m-cz[i]<0){
            cout<<i-1;
            return 0;
        }
        m=m-cz[i];
    }
    return 0;
}