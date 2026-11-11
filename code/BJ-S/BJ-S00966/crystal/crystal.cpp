#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005];
long long s[500005]={0};
long long m;
long long times[500005]={0};
int main(){
    long long ans=-1;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        times[i]=(i-1)*a[i]-s[i-1];
    }
    for(int i=1;i<=n;i++){
        if(times[i]<=m&&i>ans){
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}
