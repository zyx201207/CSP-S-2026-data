#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	s+='0';
	cin>>n;
	int e=1;
	for(int i=1;i<=n;i++)
	{
		int m;
		char k;
		cin>>m>>k;
		for(int j=1;j<=m;j++)
		{
			s+=k;
			e++;
		}
	}
	e--;
	int ans=0;
	for(int i=1;i<=e/2;i++)
	{
		if(s[i]!=s[e+1-i])
		{
			s[e+1-i]=s[i];
			ans++;
		}
		
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
