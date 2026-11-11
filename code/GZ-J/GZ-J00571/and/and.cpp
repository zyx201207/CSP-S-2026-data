//GZ-J00571 贵阳实验二中 刘子墨
#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n-1;i>n-m;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
