#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[100002];
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
    }
    cout<<a[0];
    return 0;
}
