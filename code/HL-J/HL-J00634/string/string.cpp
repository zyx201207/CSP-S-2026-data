#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n,cnt=0;
	string d,s;
	string c; 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		getline(cin,c);
		s+=c;
	}
	d=s;
	int l=s.size();
	int ii=0;
	int jj=l-1;
	for(int i=0;i<l/2;i++)
	{
 		s[ii]=s[jj];
 		ii++;
 		jj--;
 	}
	for(int i=0;i<n;i++)
	{
		if(s[i]!=d[i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 