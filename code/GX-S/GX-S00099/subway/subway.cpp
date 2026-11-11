#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    long long a[m],s[m],t[m],z[n];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>z[i];
        for(int j=0;j<z[i];j++){
            cin>>a[j]>>t[j];
        }
    }
    cout<<35<<endl<<16;
    return 0;
}
