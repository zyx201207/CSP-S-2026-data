#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,a[N],q[N],h[N],cnt=0;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        q[i]=q[i-1]+a[i];
    }
    for(int i=n;i>=1;i--)h[i]=h[i+1]+a[i];
    int l=1,r=n;
    while(1){
        if(q[l-1]>=q[n]/2||h[r+1]>=q[n]/2)break;
        if(c[l]!=c[r]){
            cnt+=min(min(q[l],h[r]),q[n]/2)-max(q[l-1],h[r+1]);
        }
        if(q[l]==h[r]){
            l++;
            r--;
        }else if(q[l]>h[r])r--;
        else l++;
    }
    cout<<cnt;
    return 0;
}
