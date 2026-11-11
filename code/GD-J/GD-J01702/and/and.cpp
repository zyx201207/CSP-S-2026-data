#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=-1;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=2;i<=n;i++){
            int ans=a[i];
        for(int j=1;j<=i-1;j++){
            ans=ans&a[j];
            maxn=max(ans,maxn);
        }
    }
    cout<<maxn;
    return 0;
}
