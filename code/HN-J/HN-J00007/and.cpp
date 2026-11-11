#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],b[N],v[N],s;
dfs(int l){
	if(l==m){
		int x=b[1];
		for(int i=2;i<=m;i++){
			x=x&b[i];
		}
		s=max(x,s);
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			b[l+1]=a[i];
			v[i]=1;
			dfs(l+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<s;
	return 0;
}
