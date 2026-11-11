#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005];
long long ans;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a=sort(a,a+n);
    ans=a[n];
    for(int i=n;i>m-n;i--){
        ans=ans and a[i];
    }
    cout<<ans;
return 0;
}
