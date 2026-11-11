//GZ-J00427 兴义市弘毅中学 罗曾琦 
#include<bits/stdc++.h>
using namespace std;
long long n;
int a[1100000];
char s[1100000];
string s1;
int k=0,o=0;
long long l=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>s[i];
		l+=a[i];
		for(int j=0;j<a[i];j++)	s1=s1+s[i];
    }
	for(int i=0;i<l/2;i++)
	{
		if(s1[i]!=s1[l-1-i])
		{
			k++;
		 } 
	}
	cout<<k; 
	return 0;
 } 
