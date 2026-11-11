#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5;
int n,m,a[N],maxn=-1,s;
bool vis[N];
void dfs(int x,int y,int s) {
	maxn=max(maxn,s);
	if(x==n){
		return ;
	}
	vis[x]=true;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(x+1,i,s&a[i]);
			vis[i]=false;
		}
	}
//	if(m==3) {
//		for(int i1=1; i<=n-2; i1++) {
//			for(int i2=2; i<=n-1; i1++) {
//				for(int i3=3; i<=n-0; i1++) {
//					maxn=max(ma,a[i]&a[j]);
//				}
//			}
//		}
//	}
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(m==1) {
		int ma=-1;
		for(int i=1; i<=n; i++) {
			ma=max(ma,a[i]);
		}
		cout<<ma;
		return 0;
	} else if(m==2) {
		int ma=-1;
		for(int i=1; i<n; i++) {
			for(int j=i+1; j<=n; j++) {
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	} else if(m==n) {
		int sum=a[1];
		for(int i=2; i<=n; i++) {
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	else {
		s=a[1];
		dfs(0,0,0);
		cout<<maxn;
	}
	return 0;
}
