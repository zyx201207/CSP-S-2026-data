#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[100000];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	long long sum=a[n];
	for(int i=n;i>=1;i--){
		sum=sum&a[i];
		m--;
		if(m<=0){
			cout << sum;
			return 0;
		}
	}
	return 0;
}
