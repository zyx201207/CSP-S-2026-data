#include <bits/stdc++.h>
using namespace std;
int N,A;
char C[1000005];
string S;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>N;
	for (int i=1;i<=N;i++)
	{
		cin>>A;
		cin>>C[i];
		for (int j=1;j<=A;j++)
		{
			S+=C[i];
		}
	}
	string V;
	for (int i=S.size()-1;i>=0;i--)
		V+=S[i];
	if (S==V)
	{
		cout<<"0"; 
	}
	else
		cout<<"1";
	return 0;
} 

