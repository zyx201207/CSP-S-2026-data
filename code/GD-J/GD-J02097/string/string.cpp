#include<bits/stdc++.h>
#define int long long 
using namespace std;
int ans;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a,l=0;
	char c;
	string s;
	for(int i=1; i<=n; i++){
		cin>>a>>c;
		for(int j=1; j<=a; j++)
			s[l]=c,l++;
	}
	for(int i=0; i<l/2; i++)
		if(s[i]!=s[l-i-1])
			ans++;
	cout<<ans;
	return 0;
}
