#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e6+5;
ll n,m,a[N],s[N],ans=1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
    bool p=0;ll op=a[2]-a[1];
    for(int i=2;i<=n-1;++i){
        if((a[i+1]-a[i])!=op){p=1;break;}
    }
    if(p==0){
        ll cnt=op,ans=1;
        while(ans<=n  and m>=cnt){
            m-=cnt;
            cnt+=op;
            ans++;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;++i)s[i]=a[i]-a[i-1];
    for(int i=1;i<=n;++i){
        ll j=i,m1=m,cnt=s[i],ans1=1;
        while(j>=1 and m1>=cnt){
            j--;
            m1-=cnt;
            cnt+=s[j];
            ans1++;
        }
        ans=max(ans1,ans);
    }
    cout<<ans;
    return 0;
}
