#include<iostream>
#include<cmath>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i = 0;i < n;++i){
		cin >> a[i];
	}
	long long ans = a[0];
	for(long long i = 0;i < m;i++){
		for(long long j = 0;j < n - 1;++j){
			ans = max(a[j],a[j]&a[j+1]);
			a[j]=ans;
		}
	}
	cout<<ans;
	return 0;
}
