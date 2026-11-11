//FJ-J00067 FJ-S00073
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll n,m,a[10001],maxn=0;
bool pd(ll o){
	ll value=a[o],tot=0;
	for(ll i=1;i<=n;i++)tot+=(value-a[i]);
	return tot<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		if(pd(i))maxn=max(maxn,i);
	}
	cout<<maxn;
}       












