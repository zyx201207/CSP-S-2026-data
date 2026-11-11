#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
long long a[20000009];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    m-=2;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if((a[i] & a[i+1])<=(a[i+1] & a[i+2])) k=a[i+1]&a[i+2];
        while(m--){
            if(k&a[i]<k&a[i+1]) k=k&a[i+1];
        }
    }
    cout<<k;
    return 0;
}
