#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
//const int N=1e5+10;
int n,a[200010],cnt;
char c[200010];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	} 
	int i=1,j=n;
	while(i<j){
		if(c[i]!=c[j]) cnt+=min(a[i],a[j]);
		int x=min(a[i],a[j]);
		a[i]-=x,a[j]-=x;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<cnt;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
