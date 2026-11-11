//GZ-J00445   遵义市新浦新区滨湖中学   范曾
#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+0,a+n,cmp);
	int ans=a[0];
	for(int i=1;i<m;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

