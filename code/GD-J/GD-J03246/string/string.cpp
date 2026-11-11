#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,y=0,c=0;
    freopen("string.in");
	freclose("string.out");
	int n[a+1];
	char m[a+1];
	string s;
	string x;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=n[i];j++)
		{
			s[y]=m[i];
			y++;
		}
	}
	int z=y;
	int o=z-1;
	for(int i=0;i<z/2;i++)
	{
		if(s[i]!=s[o])
		{
			c++;
		}
		o--;
	}
	cout<<c;
	return 0;
}
