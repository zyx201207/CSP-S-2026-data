#include<bits/stdc++.h>
using namespace std;
const int N=1e6;

int main(){
 freopen("migrate.in.in","r",stdin);
   freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
            int a[N];
        int n,d;
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        cin>>a[j];
        if(c==0)cout<<0<<" "<<1;
        if(a[2]-a[1]>d)cout<<0;
        if(a[2]-a[1]<d){
            int g=d/(a[2]-a[1]);
             int ans=n*n/(g*(g-1)/2);
             cout<<ans;
        }
      cout<<0;
        //int ans=n*(n-1)/2;
       //cout<<ans;
    }
}
