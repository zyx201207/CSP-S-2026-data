#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int ans=a[1];
	int i=1;
	for(int j=2;j<=m;j++){
		i++;
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
