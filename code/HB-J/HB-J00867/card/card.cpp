#include<bits/stdc++.h>
using namespace std;
int t[300030];
int ans[300030];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        t[tmp]++;
    }
    for(int i=1;i<=m;i++){
        ans[i]=ans[i-1]+t[i];
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';

    return 0;
}
