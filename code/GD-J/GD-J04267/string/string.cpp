#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,a;
	cin>>n;
	char b;
	
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		while(a--) s+=b;
	}
	string l=s.substr(0,s.size()/2);
	string r=s.substr(s.size()-s.size()/2,s.size()-1);
	reverse(r.begin(),r.end());
	
	long long ans=0;
	for(int i=0;i<s.size()/2;i++)
		if(l[i]!=r[i]) ans++;
	cout<<ans;
} 
