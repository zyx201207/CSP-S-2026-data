#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2E5+10;
struct node{
    char c;
    int cnt;
}a[N];int ans=0,n,i,j;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].cnt>>a[i].c;
    for(i=1,j=n;i<j;i++,j--){
        if(a[i].c!=a[j].c)j--,ans+=a[i].cnt+a[j].cnt;
        else if(a[i].cnt!=a[j].cnt&&j!=i+1)ans+=abs(a[i].cnt-a[j].cnt);
    }if(n%2!=0)cout<<ans-1;
    else cout<<ans;
}signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
    solve();
    return 0;
}
