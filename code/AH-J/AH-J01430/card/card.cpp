#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main(){
    /*freopen("card1.in","r",stdin);
    freopen("card1.out","w",stdout);*/
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        a[t]=i;
    }
    for(int i=1;i<=m;i++){
        cout<<a[i]<<' ';
    }
}
