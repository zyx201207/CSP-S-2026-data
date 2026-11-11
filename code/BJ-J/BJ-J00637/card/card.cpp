#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    a[n+1]=-111;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[i+1]){
            cout<<i<<' ';
        }
    }
}