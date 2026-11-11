#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],b[500010],ans=1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
    int l=1;
    for(int r=1;r<=n;r++){
        while((a[r]*(r-l+1)-(b[r]-b[l-1]))>m)l++;
        ans=max((long long)r-l+1,ans);
    }
    cout<<ans;
    return 0;
}
