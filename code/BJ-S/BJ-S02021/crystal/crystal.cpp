#include <bits/stdc++.h>
using namespace std;
long long l[500005];
long long p[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>l[i];

    }
    sort(l+1,l+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            p[i]+=l[i]-l[j];
        }
    }
    for(int i=n;i>0;i--){
        if(p[i]<=m){
            cout<<i;
            return 0;
        }
    }
    return 0;
}
