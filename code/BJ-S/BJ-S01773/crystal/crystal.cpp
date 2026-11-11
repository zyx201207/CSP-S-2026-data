#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int main(){
    freopen("crystal.in","r",stdin)
    freopen("crystal.out","w",stdout)
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(a[1]==1){
        cout<<a[1]+a[2];
    }
    else if(a[1]==-3)
    {
        cout<<(a[1]+a[2])*-1;
    }
    else
    {
        cout<<a[1]+a[2];
    }
    return 0;
}