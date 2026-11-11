#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string ans;
	for(int i=1;i<=n;i++)
	{
		int temp;
		char c;
		cin>>temp>>c;
		for(int i=1;i<=temp;i++) 
			ans+=c;
	}
	long long temp=0;
	for(int i=0;i<ans.size()/2;i++)
		if(ans[i]!=ans[ans.size()-i-1]) temp++;
	cout<<temp;
	return 0;
} 
