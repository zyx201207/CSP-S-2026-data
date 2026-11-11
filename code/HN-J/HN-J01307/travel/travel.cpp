#include<bits/stdc++.h>
using namespace std;
string x1,x2,b1,b2;
int s1,s2,t1,t2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>x1;
	cin>>b1;
	cin>>x2>>b2;
	if(x1[0]=='0')s1=int(int(x1[1])-48);
	else s1=int(x1[0]-48)*10+int(x1[1]-48);
	
	if(x2[0]=='0')s2=int(int(x2[1])-48);
	else s2=int(x2[0]-48)*10+int(x2[1]-48);
	
	if(b1[0]=='0')t1=int(int(b1[1])-48);
	else t1=int(b1[0]-48)*10+int(b1[1]-48);
	
	if(b2[0]=='0')t2=int(int(b2[1])-48);
	else t2=int(b2[0]-48)*10+int(b2[1]-48);
	if(s1==s2)cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	
	if(t1==t2)cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	} 
	
	if(b1[2]>='A' && b2[2]>='A' && b1[2]<='C' && b2[2]<'C' || b1[2]>='D' && b2[2]>='D' && b1[2]<='F' && b2[2]<'F')cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	
	if(char(b1[2]+1)==b2[2] && b1[2]!='C' || char(b1[2]-1)==b2[2] && b1[2]!='D')cout<<1;
	else cout<<0;





	return 0;
}

