#include<bits/stdc++.h>
using namespace std;
long long a[10000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a+1,a+1+n,greater<int>());
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		ans=a[i]&ans;
	}
	cout<<ans;
	return 0;
}
