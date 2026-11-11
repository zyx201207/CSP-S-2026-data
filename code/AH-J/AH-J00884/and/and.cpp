#include<bits/stdc++.h>
using namespace std;
int ma=-1,mi=100000,mx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	#define int long long
	int n,a[100000],b[100000],c[100000];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(ma<=a[i]) ma=a[i];
		if(mi>=a[i]) mi=a[i];
		b[a[i]]++;
	}
	cout<<ma;
	return 0;
}
