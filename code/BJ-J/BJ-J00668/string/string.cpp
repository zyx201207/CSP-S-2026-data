#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q[N];
char c[N];
long long a[N],ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int t=n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<n/2;i++){
        int t=n-i+1;
        if(q[t]) t--;
        if(c[t]==c[i]) ans+=abs(a[i]-a[t]);
        else{
            if(a[i]>a[t]){
                ans+=a[i];
                for(int j=t-1;j>=t-(a[i]-a[t]);j--) q[j]=1;
            }
            else ans+=a[t];
            for(int j=i+1;j<=i+(a[t]-a[i]);j++) q[j]=1;
        }
    }
    if(c[n/2]!=c[n/2+1]) ans+=min(a[n/2],a[n/2+1]);
    cout<<ans;
    return 0;
}
