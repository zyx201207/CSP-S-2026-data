#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=0;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		cin>>a[1];
		ans=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	if(m==1){
		cout<<ans;
		return 0;
	}
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
