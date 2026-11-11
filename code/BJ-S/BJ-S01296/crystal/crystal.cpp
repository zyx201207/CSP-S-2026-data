#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    int n;
    cin>>n;
    long long m;
    cin>>m;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    if(m%2==1){
        m=m+1;
        ans=m/2;
    }
    else if(m%2==0){
        ans=m/2;
    }
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cout<<ans;
    return 0;
}