#include<bits/stdc++.h>
using namespace std;
int cx(string a,string b){
	if(a==b){
		return 1;
	}
	else
	{
		return 0;
	}
}
int tp(string a,string b){
	if(a[0]==b[0]&&a[1]==b[1]){
		return 1;
	}
	else
	{
		return 0;
	}
}
int tc(string a,string b){
	if((a[2]<='C'&&b[2]<='C')||(a[2]>='D'&&b[2]>='D')){
		return 1;
	}
	else
	{
		return 0;
	}
}
int xl(string a,string b){
	if(a[2]==b[2]+1||a[2]+1==b[2]||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D')){
		return 1;		
	}
	else
	{
		return 0;
	}
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(cx(a,c)==1){
		if(tp(b,d)==1){
			if(tc(b,d)==1){
				if(xl(b,d)==1){
					cout<<"1111";
				}
				else
				{
					cout<<"1110";	
				}
			}
			else
			{
				cout<<"1100";
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
