#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],b[N];
int n,ans;
ll m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=1,l=0;i<=n;i++){
        while(a[i]*(i-l)-(b[i]-b[l])>m)l++;
        ans=max(ans,i-l);
    }
    cout<<ans<<"\n";
    return 0;
}
/*
5 5
1 2 4 8 9

*/
