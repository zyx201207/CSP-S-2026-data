#include<bits/stdc++.h>

using namespace std;

long long n,m,a[500001],s[500001],ans;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;

    for(long long i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+n+1);

    for(long long i=1;i<=n;i++) s[i]=s[i-1]+a[i];

    ans=1;

    while(a[ans+1]*ans-s[ans]<=m)ans++;

    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
