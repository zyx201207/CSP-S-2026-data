#include <bits\stdc++.h>
using namespace std;
int m,n;
int a[1000005];
long long mx=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			if(a[j]&a[j+1]>mx) mx=a[j]&a[j+1];
		}
	}

	cout<<mx;
	return 0;
}
