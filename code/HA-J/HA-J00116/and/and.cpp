#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N],b[N],c[N];
long long ma=-0x3f3f3f3f;
void dfs(int k){
	if(k>m){
		long long t=b[1];
		for(int i=2;i<=m;i++){
			t=b[i]&t;
		}
		ma=max(ma,t);
		return;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			b[k]=a[i];
			c[i]=1;
			dfs(k+1);
			c[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ma;
	return 0;
}

