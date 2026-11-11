#include<bits/stdc++.h>
using namespace std;
int a[200005];
int awy(int x,int y){
	return x&y;
}
int cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=awy(a[1],a[2]);
	for(int i=3;i<=m;i++){
		ans=awy(ans,a[i]);
	}
	cout<<ans;
	return 0;
}
