#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;
cin>>n>>m;
int a[10005];
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
int ans=0;
int k=0;
for(int i=n;i>=1;i--){
    if(a[i]!=k){
        ans++;
        k=a[i];
    }
    if(ans==m){
        cout<<k;
        return 0;
    }
}
return 0;
}