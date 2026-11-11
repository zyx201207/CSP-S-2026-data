#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r";stdin);
    //freopen("travel.out","w";stdout);
    int n;
    cin>>n;
    int m;
    cin>>m;
    int a[n+1];
    int x=1;
    for(int i=0;i<m;i++){
        x*=(n-i);
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans[x];
    for(int i=1;i<=n-m+1;i++){
        ans[i]=a[i];
        for(int j=i;j<=m;j++){
            ans[i]=ans[i] and a[j];
        }
    }
    sort(ans+1;ans+n-m+2);
    cout<<ans[n-m+1];
    return 0;
}