#include <bits/stdc++.h>
using namespace std;
int a[200010];
bool cmp(int a1,int a2){
    return a1>a2;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w".stdout);
    int n,m,ans;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1];
    for (int i=2;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
