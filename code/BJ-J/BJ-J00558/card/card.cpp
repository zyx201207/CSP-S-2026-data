#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n,a[100000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<m<<a[1]<<a[3];
    return 0;
}
