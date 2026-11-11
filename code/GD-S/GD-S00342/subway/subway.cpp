#include <bits/stdc++.h>
using namespace std;
int mz(x,y){
	if (a=1){
		return;
	}
	for(int i=0;i<a[x];i++){
		mz()
	}
} 
zuiduan=0; 
dangqian=0
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,y;
	cin>>c>>n>>m>>d>>q;
	int w[m];//——线走到大厅时间 
	int a[n];//第——站经过几条线 
	int t[n];//走路到——线时间 
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>a[i]>>t[i];
	}
	cin>>x>>y;
	for(q;q>0;q--){
		cout<<mz(x,y)<<" ";
	}
	return 0;
} 
