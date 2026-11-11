#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans;
int a[200005];
bool cmp(int x,int y){
	if (x>=y){
		return true;
	}
	else{
		return false;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if (m==0){
		cout<<'0';
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for (int i=2;i<=m;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}
