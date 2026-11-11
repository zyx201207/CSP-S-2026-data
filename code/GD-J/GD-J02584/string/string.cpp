#include<iostream>
#include<cstdio>
using namespace std;
int n,cnt;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		string c;
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			s+=c;
		}	
	} 
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			cnt++;
			s[s.size()-i-1]=s[i];
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
