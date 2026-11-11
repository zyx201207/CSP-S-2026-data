#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=1+n-m;i++){
		long long p=a[i];
		for (int j=i+1;j<i+m;j++){
			p=p&a[j];
		}
		ans=max(p,ans);
	}
	cout<<ans;
	return 0;
}
