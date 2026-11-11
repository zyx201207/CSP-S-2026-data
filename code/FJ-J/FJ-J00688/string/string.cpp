#include<bits/stdc++.h>
using namespace std;
int n,m1,k=0,g=0;
char m2;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m1>>m2;
		while(m1!=0)
		{
			s+=m2;
			m1--;
		}
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[s.size()-i-1]!=s[i])
		{
			g++;
		}
	}
	cout<<g;
	return 0;
}

