#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,a[N],ans,cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int> ());
	for(int i=1;i<m;i++){
		cnt=(a[i]&a[i+1]);
		ans=(cnt&(a[i]&a[i+1]));
	}
	cout<<ans;
	return 0;
}

