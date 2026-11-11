#include<bits/stdc++.h>
using namespace std;
long long int n;
long long int m;
long long int a[200010];
long long int ans1;
long long int ans2=-1e5;
long long int b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b=n-(m-1);
	for(long long int i=1;i<=b;i++){
		for(long long int j=i+1;j<=n;j++){
			ans1=a[i];
			ans1&=a[j];
			ans2=max(ans1,ans2);
		}
	}
	cout<<ans2;
	return 0;
}

