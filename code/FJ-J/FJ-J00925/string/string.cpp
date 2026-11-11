#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string S;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		int a;
		char c;
		cin>>a>>c;
		while(a--)
			S+=c;
	}
	int size=S.size();
	for(int i=0;i<=size/2;i++)
		if(S[i]!=S[size-i-1])
		{
			//cout<<i;
			cnt+=1;
		}
	cout<<cnt;
	return 0;
}
