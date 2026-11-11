#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
bool b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        if(bool[a[i]])break;
        cout<<a[i];
        bool[a[i]]=1;
    }
    cout<<n;
    return 0;
}
