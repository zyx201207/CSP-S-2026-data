#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	cout<<ans;
	return 0;
}
