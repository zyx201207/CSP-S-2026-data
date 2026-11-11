#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,ans,cnt;
ll m,a[N],nd;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        nd+=(a[i]-a[i-1])*cnt;
        cnt++;
        while(nd>m){
            nd-=a[i]-a[i-cnt+1];
            cnt--;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<'\n';
    return 0;
}
