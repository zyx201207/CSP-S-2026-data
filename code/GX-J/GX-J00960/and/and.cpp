#include<bits/stdc++.h>
using namespace std;
int n,m,ans=2147483647,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<=m;ans&=a[n-i],i++);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
