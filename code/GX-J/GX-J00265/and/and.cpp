#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005],ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    for(int i=1;i<=m;i++){
        ans=a[n]&a[n-1];
    }
    cout<<ans;
    return 0;
}
