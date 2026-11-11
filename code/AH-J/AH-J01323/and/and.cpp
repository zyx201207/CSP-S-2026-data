#include<bits/stdc++.h>
using namespace std;
const int N=10000001;
long long a[N],n,m;
long long ans=0;
int main(){
     freopen("and.in","r",stdin);
     freopen("and.out","w",stdout);
     ios::sync_with_stdio();
     cin>>n>>m;
     for(int i=1;i<=n;i++){
        cin>>a[i];
     }
     sort(a+1,a+n+1);
     for(int i=n-1;i>n-m;i--){
        ans=ans&a[i];
     }
     cout<<ans;
     return 0;
}
//Trick||Treat!
