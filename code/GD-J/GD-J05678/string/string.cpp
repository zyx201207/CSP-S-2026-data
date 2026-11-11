#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string s;
	cin>>n;
	int m;
	char a;
	for(int i=1;i<=n;i++)
	{		
		cin>>m;
		cin>>a;
		//cout<<m;
		for(int j=0;j<m;j++)
		{		
			s+=a;
		}
	}
	//cout<<s;
	int lo=s.size();
	//cout<<lo;
	int w=0;
	for(int i=0;i<lo/2;i++)
	{
		if(s[i]!=s[lo-i-1])
		{
			w++;
		}
	}
	cout<<w;
	
	return 0;
}
