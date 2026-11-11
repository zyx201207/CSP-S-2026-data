#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000100];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i+1]){
            cout<<i<<" ";
        }
    }
    return 0;
}
//10 3
//2 3 1 2 1 3 2 3 1 2 1
