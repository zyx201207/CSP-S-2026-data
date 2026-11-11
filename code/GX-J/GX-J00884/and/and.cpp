#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,max1=-10086;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        int ans=a[i];
        for(int j=i+1;j<m;i++) ans=ans&a[j];
        max1=max(max1,ans);
    }
    cout<<max1<<'\n';
    return 0;
}
