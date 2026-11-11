#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 1e6 + 5; 

int a[N];

bool cmp(int x, int y){
	return x>y;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=m;i++){
		a[i-1]&=a[i];
	}
	cout<<a[m];
	return 0;
}
