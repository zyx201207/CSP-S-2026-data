#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],q,w;
int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++){
        q=a[i] and a[i+1];
        w=a[i];
        for(int k = 1;k<=m;k++){
            for(int j = i+2;j<=n;j++) q=max(w and a[j],q);
            w=q;
            q=0;
        }
    }
    cout<<w;
    return 0;
}