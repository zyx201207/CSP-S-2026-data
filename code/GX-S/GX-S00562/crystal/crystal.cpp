#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[500010],c[500010],f[500010];
ll m;


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n>>m;
    for (int i=1;i<=n;i++){
        cin >>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        c[i]=a[i]-a[i-1];

    for (int i=1;i<=n;i++){
        f[i]=f[i-1]+(i-1)*c[i];
    }
    for (int i=1;i<=n;i++){
        if(f[i]==f[i+1])
            continue;
        else {
        if(f[i]==m){
            cout<<i<<"\n";
            break;
        }
        if(f[i]>m){
            cout <<i-1<<"\n";
            break;}
        }
    }

    return 0;
}



