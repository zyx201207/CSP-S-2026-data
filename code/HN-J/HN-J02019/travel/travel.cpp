#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel""r".in);
	//freopen("travel""w".out);
	string c;
	string s;
	for(int i=0;i<2;i++)
	{
		cin>>c[i]>>s[i];
	}
	for(int i=0;i<2;i++)
	{
		if(c[1]!=s[1])
		{
			cout<<0;
		}
		else{
			cout<<1; 
		}
		if(c[2]!=s[2]+1||s[2]!=c[2]+1)
		{
			cout<<0;
		}
		else{
			cout<<1; 
		}
	}
	return 0;
} 
