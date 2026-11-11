#include<bits/stdc++.h>
using namespace std;
int n,m,ans[500009],a[500009],last[500009],s[500009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=i;
        last[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        cout<<s[last[i]]<<' ';
    }
    return 0;
}
