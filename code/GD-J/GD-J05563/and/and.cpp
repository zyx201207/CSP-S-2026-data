#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[20005],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}cout<<ans;
	return 0;
}
