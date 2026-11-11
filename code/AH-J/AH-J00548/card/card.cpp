#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a[n];
    for(int i=1;i<=n;i++){\
    cin>>a[i];
    if(a[i]!=a[i-1]){
    cout<<a[i];
    }
    }

    return 0;
}
