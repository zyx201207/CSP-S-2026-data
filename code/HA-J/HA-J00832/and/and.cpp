#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin >> n >> m;
	if(m==1) cout << a[n-1];
	if(m==2) cout << (a[n-1]^a[n-2]);
	
	return 0;
}

