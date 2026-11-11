#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[n+1];
    char c[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    if(a[1]==1 && a[2]==1) {
        if(c[1]!=c[2]) cout<<1;
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
