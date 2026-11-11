#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ikun="woshixiaohezi";//I'm true ikun
const int maxn=1e6+10;
ll n,m,a[maxn],t[maxn],p[maxn];
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]=i;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			t[a[j]]++;
			j=max(j,p[a[j]]);
		}
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<" ";
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    solve();
    return 0;
}
//Trick||Treat!
