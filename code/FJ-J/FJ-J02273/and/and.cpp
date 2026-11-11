#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int a[200010];

bool cmp(int a,int b){
	return a>b;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[1]; 
	return 0;
}
