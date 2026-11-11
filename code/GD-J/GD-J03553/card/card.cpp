#include<bits/stdc++.h>
using namespace std;
long long n,m,q[110],vis[99999999],b[1000],maxv;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	for(int i=3;i<=m;i++){
		cout<<q[i];
	}
	return 0;
}
