#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdin);
    int n,m;
    long long a;
    cin>>n>>m;
    for(int i=0;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=0;
    int ans=1;
    for(inti=1;i<=n;i++){
        a-=(a[i]-a[i-1])*(i-1);
        while(m<0){
            i++;
        }
        ans=max(ans,il+i);
    }
    cout<<ans;
    return 0;
}