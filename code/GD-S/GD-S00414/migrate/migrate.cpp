#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000006;
const int inf=0x3f3f3f3f;
int n,d;
int a[N];
int cnt=0;
int mn=inf;
//vector<int> aa;
void dfs(int x,int v,int l) {
	if(l>mn) return;
	if(x==v) {
		if(l==mn) {
			cnt++;
//			cout<<"plus\n";
		} else {
//			cout<<"clear : "<<mn<<" -> "<<l<<"\n";
			mn=l;
			cnt=1;
		}
//		for(int i : aa) cout<<i<<" ";cout<<"\n";
		return;
	}
	for(int i=v; i>x; i--) {
		if(a[i]-a[x]<=d) {
//			aa.push_back(i);
			dfs(i,v,l+1);
//			aa.pop_back();
		}
	}
}
bool check(int u,int v) {
//	int len=0;
//	for(int i=u;i<=v;){
//		bool f=true;
//		for(int j=i+1;j<=v;j++){
//			if((j!=v&&a[j]-a[i]<=d&&a[j+1]-a[i]>d)||j==v){
//				len++;
//				i=j;
//				f=false;
//				break;
//			}
//		}
//		if(f){
//			return false;
//		}
//	}
//	cout<<"check : "<<u<<" ~ "<<v<<"\n";
	cnt=0;
	mn=inf;
//	aa.push_back(u);
	dfs(u,v,0);
//	aa.pop_back();
	return cnt==2;
}
void work() {
	cin>>n>>d;
	if(n<=300) {
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		int ans=0;
		for(int i=1; i<=n-1; i++) {
			for(int j=i+1; j<=n; j++) {
				if(check(i,j)) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	else{
		int det;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		det=a[n]-a[n-1];
		if(d<2*det){
			cout<<0<<"\n";
			return;
		} else{
			int leap=d/det;
			cout<<max(0ll,n-leap-leap+1)<<"\n";
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		work();
	}
	return 0;
}
/*
部分分:8pts
枚举岛屿对，分别判断是否为”双径岛屿对“
枚举n^2+最短路径2^n
8+8=16
*/
