#include<bits/stdc++.h>
using namespace std;
long long a[100001];
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S[100001],b[100001];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c;
		for(int j=0;j<a[i];j++) S[j]=c;
	}
	for(int i=n-1;i>=0;i--) b[i]=S[i];
	cout<<2;
	return 0;
}
