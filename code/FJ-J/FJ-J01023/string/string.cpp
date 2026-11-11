#include<iostream>
#include<cstring> 
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	string s; 
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	string t;
	for(int i=s.size()-1;i<=0;i--)
	{
		t+=s[i];
	}
	int sum=0;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(t[i]!=s[i])
			sum+=1;
	}
	cout<<sum/2;
	return 0;
}
// freopenÈ¥×¢ÊÍ
//mdT2jisi
//shenmepoT2
