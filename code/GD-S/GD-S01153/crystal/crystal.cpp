#include<bits/stdc++.h>
using namespace std;

int m,n,ans,a[500005];

void cacu(){
	int d[500005];
	d[1]=0;
	for(int i=1;i<=n;i++){
		d[i+1] = d[i] + i*(a[i+1]-a[i]);
		if(d[i]<=m) ans = i;
		if(d[i]>m) break;
	}
}

bool cmt(int x,int y){
	return x < y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	sort(a+1,a+n+1,cmt);
	cacu();
	
	cout << ans;
	return 0;
}
