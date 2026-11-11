#include<bits/stdc++.h>
using namespace std;
long long a[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long s=a[n];
	for(int i=n;i>=n-m;i--){
		s&=a[i];
	}
	cout<<s<<'\n';
	return 0;
}
