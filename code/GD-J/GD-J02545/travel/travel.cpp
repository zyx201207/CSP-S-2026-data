#include<bits/stdc++.h>

using namespace std;
int c1,c2;
string s1,s2;
bool q1,q2,q3,q4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int zs1,zs2;
	int k1,k2;
	zs1=(s1[0]-'0')*10+(s1[1]-'0');
	zs2=(s2[0]-'0')*10+(s2[1]-'0');
	if(s1[2]=='A') k1=100;
	else if(s1[2]=='B') k1=200;
	else if(s1[2]=='C') k1=300;
	else if(s1[2]=='D') k1=400;
	else if(s1[2]=='E') k1=500;
	
	if(s2[2]=='A') k2=100;
	else if(s2[2]=='B') k2=200;
	else if(s2[2]=='C') k2=300;
	else if(s2[2]=='D') k2=500;
	else if(s2[2]=='E') k2=600;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(c1==c2){
		q1=true;
		if(zs1==zs2){
			q2=true;
			if(k1<=300&&k2<=300||k1>300&&k2>300){
				q3=true;
				if(k1==k2-100||k2==k1-100){
					q4=true;
				}
			}
		}
	}
	cout<<(q1==true?1:0)<<(q2==true?1:0)<<(q3==true?1:0)<<(q4==true?1:0);
	return 0;
} 
