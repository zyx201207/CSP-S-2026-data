#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(true);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	  cout<<1;
	else{
		cout<<"0000"<<endl;
		return 0; 
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1])
	  cout<<1;
	else{
		cout<<"000"<<endl;
		return 0;
	}
	char a=s2[2],b=s4[2];
	if(((a<='C'&&b<='C')||(a>='D'&&b>='D')))
	  cout<<1;
	else{
		cout<<"00"<<endl;
		return 0;
	}
	if(abs(int(a)-int(b))==1)
	  cout<<1;
	else
	  cout<<0;
	return 0;
}
//Trick||Treat!
