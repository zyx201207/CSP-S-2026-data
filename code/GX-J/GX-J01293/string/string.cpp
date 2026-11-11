#include<bits/stdc++.h>
using namespace std;
int ass[200005]={0};
string a;
string S;	
int main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int n=0;
	int ji=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ass[i]>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<ass[i];j++)
		{
			S[ji]=a[i];
			ji+=1;
		}
	}
	int ans=0;
	for(int i=0;i<ji/2+1;i++)
	{
		if(S[i]==S[ji+1-i])
		{
			
		}
		else
		{
			S[ji+1-i]=S[i];
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}
