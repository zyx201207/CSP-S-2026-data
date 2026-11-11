#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	//前两位转数字 
	int d1=s1[0]*10+s1[1];
	int d2=s2[0]*10+s2[1];
	//判断字母
	int j1,j2;
	if(s1[2]=='D'||s1[2]=='E') j1=1;
	else j1=0;
	if(s2[2]=='D'||s2[2]=='E') j2=1;
	else j2=0;
	//字母的码
	int q1=s1[2]+0;
	int q2=s2[2]+0; 
	if(c1==c2){
		if(d1==d2){
			if(j1==j2){
				if(q1-q2==1||q2-q1==1){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
