#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
string s;
int sum;
int N;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		N+=x;
		for(int j=1;j<=x;j++)
		{
			s+=y;
		}
	}
	for(int i=0,j=N-1;i<=j;i++,j--)
	{
		cout<<s[i]<<" "<<s[j]<<endl;
		if(s[i]!=s[j])
		{
			sum++;
		}	
	}
	cout<<sum<<endl;
	return 0;
}
