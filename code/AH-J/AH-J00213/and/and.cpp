#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],msk=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=29;i>=0;i--){
		ll nmsk=msk|(1<<i),s=0;
		for(int i=1;i<=n;i++) s+=(nmsk&a[i])==nmsk;
		if(s>=m) msk=nmsk;
	}
	cout<<msk;
	return 0;
}
