#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=-1;
	cin>>n>>m;
	int a[n+9];
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<m;i++){
		maxx=(a[i]&a[i+1]);
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
