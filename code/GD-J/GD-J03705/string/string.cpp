#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,a[N];
char c[N];
ll sum,len[N],ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];len[i]=len[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(len[i-1]>=sum/2) break;
        ll l=len[i-1]+1,r=min(len[i],sum/2);
        if(l>r) break;
        int p1=lower_bound(len+1,len+1+n,sum-r+1)-len;
        int p2=lower_bound(len+1,len+1+n,sum-l+1)-len;
        if(p1>p2) continue;
        if(p1==p2){
            if(c[p1]!=c[i]) 
                ans+=(r-l+1);
        }else{
            if(c[p1]!=c[i]){
                ans+=(len[p1]-(sum-r+1)+1);
            }
            if(c[p2]!=c[i]){
                ans+=((sum-l+1)-len[p2-1]);
            }
            for(int j=p1+1;j<=p2-1;j++){
                if(c[i]!=c[j])
                    ans+=a[j];
            }
        }
    }
    cout<<ans;
    return 0;
}