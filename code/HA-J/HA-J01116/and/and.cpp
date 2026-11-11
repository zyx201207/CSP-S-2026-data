#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	int n,m,arr[100005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cout<<arr[n-2];
	return 0;
};
