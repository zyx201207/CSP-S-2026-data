#include<bits/stdc++.h>
using namespace std;
//#define int long long
//int p[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    int a[500010];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
//    for(int i=1;i<=n;i++){
//        p[i]=a[i]-p[i-1];
//    }
    int y=a[2]-a[1];
    int u=1,ans=1,o=y;
    while((o+y*u)<=m){
        ans++;
        u++;
        o+=y*u;
    }
    cout<<ans;
    return 0;
}
