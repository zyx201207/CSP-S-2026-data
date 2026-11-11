#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n,m,a[N],sum;
bool cmp(int x,int y){
	return x > y;
}
signed main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	sum = a[1];
	cout<<sum<<"\n";
	for(int i = 2;i<=m;i++){
		sum = (sum & a[i]);
		cout<<sum<<" "<<a[i]<<'\n';
	}
	cout<<sum<<'\n';
	return 0;
}
