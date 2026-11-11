#include<iostream>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200100]={},ans=0,b=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b=max(b,a[i]);
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,a[i]&a[j]);
        }
    }
    if(m==1) cout<<b;
    else cout<<ans;
    return 0;
}
