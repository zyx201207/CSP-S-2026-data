#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0,huo;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=m;j++){
            ans=max(a[i]&a[j],ans);


        }
    }
    cout<<ans;
    return 0;

}
