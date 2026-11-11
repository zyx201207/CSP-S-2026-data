#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=500007;

ll v[MAXN],edge[MAXN];
int n,m,l=1,cnt=1,ans=0;
ll s=0,s1=0; // s sum

int main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v,v+n);
    for(int i=1;i<n;i++)edge[i]=v[i]-v[i-1];
    for(int i=1;i<n;i++){
        s+=(cnt)*edge[i];
        s1+=edge[i];
        if(s>m){ans=max(ans,cnt);s-=s1;s1-=edge[l];l++;cnt--;}
        cnt++;
    }
    cout<<ans;
    return 0;
}

// standard method: tanxin
// finish: 15:31
