//GZ-J00320   Îâº«·É 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a,b,c,d[n];
	string s[10005];
	cin>>a>>d[0]>>b>>d[1]>>c>>d[2];
	for(int i=0;i<a;i++)
	{
		s[i]='a';
	}
	for(int i=a;i<a+b;i++)
	{
		s[i]='b';
	}
	for(int i=a+b;i<a+b+c;i++)
	{
		s[i]='c';
	}
	int sum=0;
	for(int i=0;i<(a+b+c)/2;i++)
	{
		if(s[i]!=s[a+b+c-i])
		{
			s[i]=s[a+b+c-i];
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
}

