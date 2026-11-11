#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);	
	string s;
	int n,m=0;
	cin>>n;
	int a[n];
	char b[n];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		m+=a[i];
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<a[i];j++)
			s[i+j]=b[j];	
	for(int i=1;i<=m;i++)
	cout<<s[i];
}
