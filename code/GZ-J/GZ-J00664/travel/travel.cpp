#include<bits/stdc++.h>
using namespace std;
int main()
 {
 	freopen("travel.in","r",in);
	freopen("tvavel.out","w",out); 
 	int a=0,c=0;
 	int m[3]={0,0,0};
 	int n[3]={0,0,0};
 	cin>>a;
 	cin>>m[3];
 	cin>>c;
 	cin>>n[3];
 	if(a>17||a<1||c<1||c>17)
	 {
	 	return 0;
	  }
 	if(a!=11&&a!=16&&c!=1&&c!=16)
 	{
	 	return 0;
	}
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(m[0]==n[0]&&m[1]==n[1])
	{
		if(m[2]=="A""B""C"&&[2]=="A""B""C"||m[2]=="D""F"&&n[2]=="D""F")
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(m[2]+-1==n[2])
	{cout<<1;
	}
	else{
		cout<<0;
	}
 return 0;
 }
