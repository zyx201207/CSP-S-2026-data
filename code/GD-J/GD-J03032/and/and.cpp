#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int a[N + 10];
bool cmp(int x,int y){
	return x > y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i = 0;i<n;i++){
		cout<<a[i]<<endl;
	}
	int res = a[0];
	for(int i = 1;i<m;i++){
		res = res & a[i];
	}
	cout<<res;
	return 0;
}

