#include<bits/stdc++.h>
using namespace std;
int n,m,ans=pow(2,30)-1,ma;
int a[200050];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		ans=(ans&a[i]);
	}
	ma=ans;
	for(int i=m+1;i<=n;i++){
		ans=(ans|a[i-m]);
		ans=(ans&a[i]);
		ma=max(ma,ans);
	}
	cout<<ma;
	return 0;
}
//Trick||Treat!

