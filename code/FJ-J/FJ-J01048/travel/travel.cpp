#include <bits/stdc++.h>
using namespace std;
int f[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int cnt1=s1[2]-'A'+1;
	int cnt2=(s2[2]-'A'+1);
	int num1=(s1[0]-'0')*10+(s1[1]-'0');
	int num2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1!=c2){
		cout<<"0000"<<'\n';
		return 0;
	}
	else{
		f[1]=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) f[2]=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]=='D'||s1[2]=='E'){
			if(s2[2]=='D'||s2[2]=='E'){
				f[3]=1;
			}
		}
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				f[3]=1;
			}
		}
	}
	if((abs(cnt1-cnt2)==1 && num1==num2) || (cnt1==cnt2 && abs(num1-num2)==1))
	{
		if(cnt1==3&&cnt2==4 || cnt1==4&&cnt2==3){
			f[4]=0;
		}
		else{
			f[4]=1;
		}
	}
	cout<<f[1]<<f[2]<<f[3]<<f[4]<<'\n';
	return 0;
}
