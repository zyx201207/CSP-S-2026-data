#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull M=1e5*2+5;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    ull n;
    int m,a[M],x=-1;
    cin>>n>>m;
    for(ull i=0;i<n;i++){
        cin>>a[i];
    }
    for(ull i=0;i<n;i++){
        for(ull j=i+1;j<n;j++){
            if(x<(a[i]&a[j])){
                x=(a[i]&a[j]);
            }
        }
    }
    cout<<x;
    return 0;
}
