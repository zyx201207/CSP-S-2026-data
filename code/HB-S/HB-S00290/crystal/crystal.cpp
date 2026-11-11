#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        if(i>1&&a[i]-a[i-1]>=0)b[i-1]=a[i]-a[i-1];
        else if(i>1&&a[i]-a[i-1]<0)b[i-1]=a[i-1]-a[i];
    }
    while(m>=0){
        ans++;
        m-=b[ans]*ans;
    }
    cout<<ans;
    return 0;
}
