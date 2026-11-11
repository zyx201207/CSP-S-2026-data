#include<bits/stdc++.h>
using namespace std;
int n,m,cur=2,a[10000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=a[n];
    for(int i=n-1;;i--,cur++){
        if(cur>m)break;
        ans&=a[i];
    }
    cout<<ans;
}
