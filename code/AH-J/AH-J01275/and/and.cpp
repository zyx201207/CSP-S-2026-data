#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200010];
ll cnt=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    m -= 2;
    cnt = a[n]&a[n-1];
    n -= 2;
    while(m--){
        cnt = cnt&a[n--];
    }
    cout<<cnt;
    return 0;
}
