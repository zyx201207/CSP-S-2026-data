#include<bits/stdc++.h>
using namespace std;
long long n,m,mm;
long long a[20005]; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--){
		mm=max(mm,a[i]&a[i-1]);
	}
	cout<<mm;
	return 0;
}
