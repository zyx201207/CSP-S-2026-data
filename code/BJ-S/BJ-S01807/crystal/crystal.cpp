#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,p=0,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        long long r=m;
        p=1;
        for(int j=i;j<n;j++){
            if(a[j]!=a[j+1]&&r>=(a[j+1]-a[j])*p){
                r-=(a[j+1]-a[j])*p;
                p++;
                ans=max(ans,p);
            }
            else if(a[j]==a[j+1]){
                p++;
                ans=max(ans,p);
            }
            else if(r<(a[j+1]-a[j])){
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}

