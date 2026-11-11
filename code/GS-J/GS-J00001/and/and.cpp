#include<bits/stdc++.h>
using namespace std;
#define itn int
#define inl inline
#define re register
#define pos ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
const int N=2e5+10;
//开long long了否
//数组大小足够否
//freopen去掉注释了否
int n,m;
int a[N];
inl bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("r","ans.in",stdin);
	freopen("w","ans.out",stdout);
	pos;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
