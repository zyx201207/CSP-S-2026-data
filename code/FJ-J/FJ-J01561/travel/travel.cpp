#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(travel.in,'r');
	freend(travel.out,'w');
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ans1=s1[0]-'0'*10+s1[1]-'0',ans2=s2[0]-'0'*10+s2[1]-'0';
	int ans3=c1[0]-'0'*10+c1[1]-'0',ans4=c2[0]-'0'*10+c2[1]-'0';
	int d1=4,d2=0;
	int an1=0,an2=0,an3=0,an4=0;
	if(s1[2]<='C'){
		d1=1;
	}
	else{
		d1=3;
	}
	if(s1[2]<='C'){
		d2=1;
	}else{
		d2=2;
	}
	if(ans3==ans4){
		an1=1;
		if(ans1==ans2){
			an2=1;
			if(d1==d2){
				an3=1;
				if(s1[2]==s2[2]-1||s1[2]==s2[2]+1){
					an4=1;
				}
			}
			else if(d1-d2==1){
				an3=1;
				if(s1[2]==s2[2]-1||s1[2]==s2[2]+1){
					an4=1;
				}
			}
		}
	}
	cout<<an1<<an2<<an3<<an4;
	return 0;
}
