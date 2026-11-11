#include <bits/stdc++.h>
using namespace std;
int n, m;

int a[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flag = 1;
	int k =1;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		k*=2;
		if(flag) if((k-1)!=a[i]) flag = 0;
	}
	sort(a+1,a+n+1);
	if(m == 1) cout<<a[n];
	if(flag){
		cout<<a[n-m+1];
	}
	else cout<<0;
	
	
}
