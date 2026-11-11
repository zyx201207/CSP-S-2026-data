#include <bits/stdc++.h>
using namespace std;
int main()
{
	fre("travel.in","r")stdin;
	fre("travel.out","w")stdout;
	int n,m;
	string a,b;
	cin>>n>>a>>m>>b;
	if(n==m) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	string s1,s2;
	for(int i=0;i<2;i++)
	{
		s1[i]=a[i];
		s2[i]=b[i];
	}
	bool c=false;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	bool a1=false,b1=false;
	for(int i=2;i<3;i++)
	{
		if('A'<=a[i] && a[i]<='C') a1=false;
		else if(a[i]=='D' || a[i]=='F') a1=true;
		if('A'<=b[i] && b[i]<='C') b1=false;
		else if(b[i]=='D' || b[i]=='F') b1=true;
	}
	if(a1==b1) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(a1){
		cout<<"1";
	}
	else{
		if((a[2]=='A' && b[2]=='B') || (a[2]=='B' && b[2]=='C')){
			cout<<"1";
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	return 0;
}
