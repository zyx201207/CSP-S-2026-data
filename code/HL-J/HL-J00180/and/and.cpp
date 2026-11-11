#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","W",stdout);
    int n,m,nm,cmp;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int num=(n-1)*n/2;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=num;j++){
            nm=a[i]&a[i+j];
            if(nm>cmp)  cmp=nm;
        }
    }
    cout<<cmp;
return 0;
}
