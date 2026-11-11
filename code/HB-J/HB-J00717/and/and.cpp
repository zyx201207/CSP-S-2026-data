#include<bits/stdc++.h>
using namespace std;
long long n,m,max1=0,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        long long s=a[i];
        for(int j=i+1;j<i+m&&j<=n;j++){
            s=(s&a[j]);
        }
        max1=max(max1,s);
   }
   cout<<max1;
    return 0;
}
