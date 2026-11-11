#include<bits/stdc++.h>
using namespace std;
int a[5000010],t[5000010];
queue<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cout<<n/m;
    }
    return 0;
}
