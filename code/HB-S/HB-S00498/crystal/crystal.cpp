#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ull unsigned long long
#define eb emplace_back
#define umap unordered_map
#define ll long long
#define Fast1 ios::sync_with_stdio(0)
#define Fast2 cin.tie(0),cout.tie(0)
#define int long long
//xterfusion!!!
//x x xxx
//o o ooo
const int N=5e5+5;
int n,m,a[N],s[N];
void _(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=1;
    for(int i=1;i<=n;i++){
        int l=1,r=i-1,pos=-1;
        while(l<=r){
            int mid=(l+r)/2;
            int v=s[i-1]-s[mid-1];
            if(m>=a[i]*(i-mid)-v)r=mid-1,pos=mid;
            else l=mid+1;
        }if(pos==-1)continue;
        ans=max(ans,i-pos+1);
    }cout<<ans<<"\n";
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    Fast1;Fast2;int t=1;
    while(t--)_();
}
