#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long i,n,a[500005],m,ans=0,b[500005],j;
    cin>>n>>m;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++){
            int m1=m;
        for(j=i-1;j>=0&&m1>=0;j--)m1-=a[i]-a[j];
        b[i]=i-j;
        if(b[i]>ans)ans=b[i];
    }
    cout<<ans;
    return 0;
}
