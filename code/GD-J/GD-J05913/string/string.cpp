#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
char b;
string s;
int main(){
	freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		for(int j=1;j<=a;j++)
			s=s+b;
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i]) ans++;
	}
	cout<<ans;
	
	return 0;
}


