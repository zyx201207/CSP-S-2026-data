#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<long long> a(n+2);
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        long long maxn=0;
        for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
        cout<<maxn;
    }
    else if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++)ans=ans&a[i];
        cout<<ans;
    }
    else if(m==2){
        long long maxn=0;
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)maxn=max(maxn,(a[i]&a[j]));
        cout<<maxn;
    }
    else if(m==n-1){
        long long maxn=0;
        for(int i=1;i<=n;i++){
            long long k=0;
            bool flag=1;
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                if(flag&&(!k))flag=0,k=a[j];
                else k=k&a[j];
            }
            maxn=max(maxn,k);
        }
        cout<<maxn;
    }
    else cout<<0;
    return 0;
}
