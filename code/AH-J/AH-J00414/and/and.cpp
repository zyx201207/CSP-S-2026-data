#include<bits/stdc++.h>
using namespace std;
int n,m,p1=1,p2,ans;
int maxa;
int a[200005];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i-1) p1=0;
        maxa=max(maxa,a[i]);
    }
    if(m==1){
        cout<<maxa;
        return 0;
    }
    if(p1){
        for(int i=n;i>=n-m+1;i--){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    int d=a[n]&a[n-1];
    cout<<d;
    return 0;
}
