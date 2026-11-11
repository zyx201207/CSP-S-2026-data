#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,t;
long long a[N];
long long ans,k;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(c>=13 && c<=18){
        if(c>=16) sort(a+1,a+n+1);
        k=0;
        for(int i=n;i>=1;i--){
            if(m-(a[i]-a[j])>=0){
                m -= a[i]-a[j];
                ++k;
            } else break;
        }
        cout<<k<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        k=0;
        t=m;
        for(int j=i;j>=1;j--){
            if(t-(a[i]-a[j])>=0){
                t -= a[i]-a[j];
                k++;
            } else break;
        }
        ans = max(ans,k);
    }
    cout<<ans<<endl;
    return 0;
}
