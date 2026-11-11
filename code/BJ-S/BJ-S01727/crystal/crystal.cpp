#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,a[maxn],l,r,ans,q[maxn],h=1,t,sum5;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        q[++t]=a[i];
        sum5+=a[i];
        while((t-h+1)*q[t]-sum5>m && h<=t){
            sum5-=a[h];
            ++h;
        }
        ans=max(ans,t-h+1);
    }
    cout<<ans<<endl;
    return 0;
}
