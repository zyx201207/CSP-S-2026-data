#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,a[100002],c[100002];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        if(c[i]==c[i+1]){
            cout<<0;
            return 0;
        }
    }
    cout<<n/2+1;
    return 0;
}
