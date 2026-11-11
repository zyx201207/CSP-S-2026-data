#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ifstream fin("string.in");
ofstream fout("string.out");
string s,ss;
long long n,a[1000000010],ans;
int main()
{
	//freopen("string.in.cpp","r",stdin);
	//freopen("string.out","w",stdout);
	fin>>n;
	for(int i=1;i<=n;i++)
	{
		fin>>a[i]>>ss;
		s=s+ss;
	}
	for(int i=0,j=s.size()-1;i<j;i++,j--) if(s[i]!=s[j]) ans+=a[i+1]<a[j+1]?a[i+1]:a[j+1];
	fout<<ans;
	return 0;
}
	
