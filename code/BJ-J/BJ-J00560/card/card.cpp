#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
