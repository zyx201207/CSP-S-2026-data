#include <bits/stdc++.h>
using namespace std;

int n,m,a[200010],x=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]&a[j]>=x)
                x=a[i]&a[j];
        }
    }
    cout<<n;
    return 0;
}
