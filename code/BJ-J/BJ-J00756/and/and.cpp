#include <bits/stdc++.h>
using namespace std;
int a[100005];
int maxx=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            maxx=max(a[i]&=a[j],maxx);
        }
    }
    cout<<maxx;
    return 0;
}