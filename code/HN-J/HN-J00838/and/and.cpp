#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[100005];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<a[m]||a[n];
	return 0;
}
