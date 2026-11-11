#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"000"<<endl;
		return 0;
	}
	cout<<1;
	int f1=0,f2=0;
	if(s1[2]=='F'||s1[2]=='D') f1=1;
	if(s2[2]=='F'||s2[2]=='D') f2=1;
	if(f1!=f2)
	{
		cout<<"00"<<endl;
		return 0;
	}
	cout<<1;
	int m=(int(s1[2])-'0')-(int(s2[2])-'0');
	if(m!=1&&m!=-1)
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<1;
	return 0;
} 
