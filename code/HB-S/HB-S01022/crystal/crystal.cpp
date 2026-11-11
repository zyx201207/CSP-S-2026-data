#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal","r",stdin);
    freopen("crystal","w",stdout);
    long long n,m,a[16767945],s=0;
    int ab;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
        for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            s+=a[i]-a[i-j];
            if(s<=m)
                ab=max(ab,j);

        }

    }
    cout<<ab;
    return 0;
}
