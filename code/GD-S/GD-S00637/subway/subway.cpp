#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int c,n,m,d,q;
int solve(int s,int t){
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c,a,b;
		cin>>c>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(int i=1;i<=q;i++){
		int xr,yr;
		cin>>xr>>yr;
		solve(xr,yr);
	}
}




