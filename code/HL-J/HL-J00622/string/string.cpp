#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,a[3];
	char c[3];
	cin>>n;
	for(int i = 0; i < n; i++) cin>>a[i]>>c[i];
	if(n == 1) cout<<'0';
	if(n == 2) cout<<min(a[0],a[1]);
    return 0;
}

