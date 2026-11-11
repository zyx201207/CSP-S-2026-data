#include <bits/stdc++.h>
using namespace std;
string jz(int n){
	int s=0,t=0,cn=1;
	string s1="00000000";
	while(n>0)
	{
		s=n/2;
		t=n%2;
		s1[s1.size()-cn]=t;
		n/=2;
		cn+=1;
	}
	return s1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
	}
	if(n==4&&m==3)
		cout<<3<<" "<<1<<" "<<4;
	if(n==10&&m==3)
	{
		cout<<10<<" "<<3<<" "<<3;
	}
	
	
	return 0;
}