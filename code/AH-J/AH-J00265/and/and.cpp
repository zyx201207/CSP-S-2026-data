#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,j=0,z=0;
	cin>>n>>m;
	long long a[n],b[m];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=n-m;i<n;i++)
	{
		b[j]=a[i];
		j++;
	}
	z=b[0];
	for(int i=1;i<m;i++)
	{
		z=z&b[i];
	}
	cout<<z;
	return 0;
}
