#include<bits/stdc++.h>
using namespace std;
int main()
{
	foropen("string.in","r",std.in);
	foropen("string.out","w",std.out);
	int n;
	cin>>n;
	int S[200005]={0};
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		S[x]++;
	}
	cout<<n<<endl;
	return 0;
}
