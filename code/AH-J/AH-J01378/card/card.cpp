#include<bits/stdc++.h>
using namespace std;
int a[500005];
int t[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n;
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    t[a[n]]=n;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[n]){
            t[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
