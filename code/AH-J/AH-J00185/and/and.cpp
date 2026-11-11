#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500010],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=m;i--){
		long long ans=a[i];
		for(int j=i-1;j>=i-m+1;j--)ans=ans&a[j];
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
