#include <bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,ans=0,cnt=0;
    long long m,st,k=0;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    st=a[n/2+1];
    for (int i=1;i<=n;i++){
        if (a[i]==st){
            cnt++;
        }
    }
    for (int i=1;i<=n/2;i++){
        b[i]=st-a[i];
    }
    sort(b+1,b+n/2+1);
    for (int i=1;i<=n/2;i++){
        if (k+b[i]>m){
            break;
        }
        k+=b[i];
        ans++;
    }
    cout<<ans+cnt;
    return 0;
}
