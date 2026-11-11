#include<bits/stdc++.h>
using namespace std;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long m;
		char c;
		cin>>m>>c;
		for(int j=1;j<=m;j++)
		{
			s+=c;
		}
	}
	string t=s;
	reverse(t.begin(),t.end());
	long long ans=0;
	long long i=0;
	while(t!=s)
	{
		ans++;
		if(s[i]!=t[i])
		{
			t[i]=s[i];
			s[s.size()-i-1]=s[i];
		}
		i++;
	}
	cout<<ans;
}
