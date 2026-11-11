#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,ans;
int a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    //for(int i=n;i>=ans;i--){//朴素思路
    //    ll ns=m,c=1;
    //    for(int j=i-1;j>=1;j--){
    //        if(a[i]-a[j]<=ns)c++,ns-=a[i]-a[j];
    //        else break;
    //    }
    //    ans=max(ans,c);
    //}
    ll l=1,r=1,s=0,c=1;
    //cerr<<1;
    while(r<n){
    //    cerr<<1;
        s+=c*(a[r+1]-a[r]);
        r++,c++;
        //cerr<<l<<" "<<r<<" "<<s<<" "<<c<<" ";
        while(s>m){
            s-=a[r]-a[l++];
            c--;
        }
        //cerr<<c<<" "<<l<<endl;
        ans=max(ans,c);
    }
    cout<<ans;
    return 0;
}
