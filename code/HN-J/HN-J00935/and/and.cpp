#include <bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<=m;i++){
		ans=ans and a[i];
	}
	cout<<ans;
	return 0;
}
