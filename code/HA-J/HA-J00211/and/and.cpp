#include <bits/stdc++.h>
using namespace std;
long long n,m,a=INT_MAX;
long long arr[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=m;i++){
		if(arr[n]<=a) a=arr[n];
		n--;
	}
	cout<<a;
	return 0;
}

