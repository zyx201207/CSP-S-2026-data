#include<bits/stdc++.h>
using namespace std;
const int N=5e5+13267;
long long a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    int ans;
    for(int i=1;i<=n;i++){
        if(a[i+1]==a[i])continue;
        long long p=a[i]*i-s[i];
        if(p>m)break;
        ans=i;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
