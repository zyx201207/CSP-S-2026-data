#include<bits/stdc++.h>
using namespace std;
longlong n,m;
int a[1000005],ans[1000005]
int main{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>n>>m;
for(int i=1,i<=n,i++){
    cin>>a[i];
    }
for(int i=1,i<=n,i++){
    ans[i]=i;
    }    
for(int i=1,i<=n,i++){
    cout<<ans[i]<<" ";
}
return 0;
}