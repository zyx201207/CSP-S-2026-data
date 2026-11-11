#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[300010];
int c[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        c[b[a[i]]]=i;
        b[a[i]]=i;
    }
    for(int i=1;i<=m;i++)
        c[b[a[i]]]=b[a[i]];
    for(int i=1;i<=m;i++){
        int ans=1;
        if(i!=b[a[i]]) continue;
        for(int j=i-1;j>=1;j--)
            if(c[j]<=i) ans++;
            else break;
        cout<<ans<<" ";
    }
    return 0;
}
