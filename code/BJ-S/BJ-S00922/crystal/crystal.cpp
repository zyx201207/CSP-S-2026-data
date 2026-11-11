#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long
const int maxn=5e5+10;
int n,ans; ll m,ai[maxn],tot;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>ai[i];
    sort(ai+1,ai+n+1);
    for(int l=1,r=1;r<=n;r++){
        tot+=(ai[r]-ai[r-1])*(r-l);
        while(tot>m)tot-=ai[r]-ai[l],l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
}