#include <bits/stdc++.h>
#define int unsigned
using namespace std;
int n,m,a[500010],answer[300010],farthest[300010];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        farthest[a[i]]=i;
    }
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j=farthest[a[j]]+1)
            answer[a[j]]++;
    for (int i=1;i<=m;i++)
        cout<<answer[i]<<" ";
    return false;
}
