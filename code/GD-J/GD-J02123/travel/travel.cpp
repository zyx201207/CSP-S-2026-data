#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,s2,s3;
	cin>>s>>s1>>s2>>s3;
	if(s==s2)
	{
		cout<<1;
		if(s1[0]==s3[0]&&s1[1]==s3[1])
		{
			cout<<1;
			if(s1[2]>='A'&&s1[2]<='C'&&s3[2]>='A'&&s3[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s3[2]>='D'&&s3[2]<='F') 
			{
				cout<<1;
				if(char(s1[2]+1)==s3[2]&&s1[2]!='C'||char(s3[2]+1)==s1[2]&&s2[2]!='C') cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
