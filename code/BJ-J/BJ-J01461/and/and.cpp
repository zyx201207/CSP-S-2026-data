#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
        a[n]&=a[n-i];
    }
    cout<<a[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}