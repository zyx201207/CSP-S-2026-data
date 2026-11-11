#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],mx=-1e7,m1;
int ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    m1=m;
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[i]-a[j]<=m){
                ans++;
                m-=a[i]-a[j];
            }
        }
        m=m1;
        mx=max(mx,ans);
        ans=0;
    }
    cout<<mx+1;
    return 0;
}
