#include<bits/stdc++.h>
using namespace std;
string c,s,c1,s1;
int flag[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1; 
	if(c==c1)
		flag[1]=1;
	else{
		for(int i=1;i<=4;i++)
			cout<<flag[i];
		return 0;
	}
	string S1="",S2="";
	S1=s.substr(0,2);S2=s1.substr(0,2);
	if(S1==S2)
		flag[2]=1;
	else{
		for(int i=1;i<=4;i++)
			cout<<flag[i];
		return 0;
	}
	if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
			flag[3]=1;
		else{
			for(int i=1;i<=4;i++)
				cout<<flag[i];
			return 0;
		}
	}
	else{
		if(s1[2]=='D'||s1[2]=='F')
			flag[3]=1;
		else{
			for(int i=1;i<=4;i++)
				cout<<flag[i];
			return 0;
		}
	}
	if(abs(s[2]-s1[2])==1)
		flag[4]=1;
	else{
			for(int i=1;i<=4;i++)
				cout<<flag[i];
			return 0;
	}
	for(int i=1;i<=4;i++)
		cout<<flag[i];
	return 0;
}
