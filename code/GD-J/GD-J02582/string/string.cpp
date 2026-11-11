#include<bits/stdc++.h>
#define int long long
#define uint unsigned long long
using namespace std;
const int mo1=1e9+7,mo2=1e9+9;
struct no{int x;char c;}a[200010];
int n,z;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].c;
	int l=1,r=n;
	while(l<r)
		if(a[l].x==a[r].x) z+=(a[l].c==a[r].c? 0 : a[r].x ),l++,r--;
		else if(a[l].x>a[r].x) z+=(a[l].c==a[r].c? 0 : a[r].x ),a[l].x-=a[r].x,r--;
		else z+=(a[l].c==a[r].c? 0 : a[l].x ),a[r].x-=a[l].x,l++;
	cout<<z;
	return ;
}
signed main(){
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0);
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
