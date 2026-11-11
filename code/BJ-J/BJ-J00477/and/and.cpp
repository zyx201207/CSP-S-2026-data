#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c=0,d=0;
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==m){
        for(int i=1;i<=n;i++){
            c+=a[i]&a[i+1];
        }
        cout<<c;
    }
    for(int i=n;i>=1;i--){
        if(i==m) cout<<d;
        d+=a[i]&a[i+1];
    }
    return 0;
}
