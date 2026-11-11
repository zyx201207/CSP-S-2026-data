#include <bits/stdc++.h>
using namespace std;
string sum[1000000];
int n,ans,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		string b;
		cin>>a>>b;
		for(int j=0;j<a;j++) sum[s+j]=b;
		s+=a;
	}
	s--;
	for(int i=0;i<s/2;i++)
	{
		if(sum[i]!=sum[s-i-1])	ans++;
	}	
	cout<<ans;	
	return 0;
}
