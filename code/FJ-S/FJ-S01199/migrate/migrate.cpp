#include <bits/stdc++.h>
using namespace std;
int x[2000006];
int w=0;
int walk=0;
int ans(int l,int n){
	walk++;
	if(l>n) return 0;
	if(l==n) return w;
	if(ans(l+1,n)==ans(l+2,n)) w++;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		ans(1,n);
	}
	return 0;
}
