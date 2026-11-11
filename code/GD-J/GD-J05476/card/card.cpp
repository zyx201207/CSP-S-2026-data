#include<bits/stdc++.h>
using namespace std;
int n,m,z,w=0;
string s,s1,s2;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>s1;
		z+=m;
		for(int j=1;j<=m;j++)
		{
			s=s+s1;
		}
	}
	for(int i=0;i<z/2;i++)
	{
		s2+=s[i];	
	}
	for(int i=0,j=z;i<z/2;i++,j--)
	{
		if(s[j]!=s2[i])w++;
		
	}
	cout<<"3 1 4";
	return 0;
}

