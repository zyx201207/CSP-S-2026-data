#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s3,s4;
int h1,h2,l1,l2,che1,che2,st1,st2;
int ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	s3=s1.substr(0,1);
	s4=s2.substr(0,1);
	if(s1[2]=="A"){
		h1=1;
	}
	else if(s1[2]=="B"){
		h1=2;
	}
	else if(s1[2]=="C"){
		h1=3;
	}
	else if(s1[2]=="D"){
		h1=4;
	}
	else if(s1[2]=="F"){
		h1=5;
	}
	if(s2[2]=="A"){
		h1=1;
	}
	else if(s2[2]=="B"){
		h1=2;
	}
	else if(s2[2]=="C"){
		h1=2;
	}
	else if(s2[2]=="D"){
		h1=2;
	}
	else if(s2[2]=="F"){
		h1=2;
	}
	if(c1=="01") che1=1;
	else if(c1=="02") che1=2;
	else if(c1=="03") che1=3;
	else if(c1=="04") che1=4;
	else if(c1=="05") che1=5;
	else if(c1=="06") che1=6;
	else if(c1=="07") che1=7;
	else if(c1=="08") che1=8;
	else if(c1=="09") che1=9;
	else if(c1=="10") che1=10;
	else if(c1=="11") che1=11;
	else if(c1=="12") che1=12;
	else if(c1=="13") che1=13;
	else if(c1=="14") che1=14;
	else if(c1=="15") che1=15;
	else if(c1=="16") che1=16;
	else che1=17;
	
	if(c2=="01") che2=1;
	else if(c2=="02") che2=2;
	else if(c2=="03") che2=3;
	else if(c2=="04") che2=4;
	else if(c2=="05") che2=5;
	else if(c2=="06") che2=6;
	else if(c2=="07") che2=7;
	else if(c2=="08") che2=8;
	else if(c2=="09") che2=9;
	else if(c2=="10") che2=10;
	else if(c2=="11") che2=11;
	else if(c2=="12") che2=12;
	else if(c2=="13") che2=13;
	else if(c2=="14") che2=14;
	else if(c2=="15") che2=15;
	else if(c2=="16") che2=16;
	else che2=17;
	
	if(s3=="01") st1=1;
	else if(s3=="02") st1=2;
	else if(s3=="03") st1=3;
	else if(s3=="04") st1=4;
	else if(s3=="05") st1=5;
	else if(s3=="06") st1=6;
	else if(s3=="07") st1=7;
	else if(s3=="08") st1=8;
	else if(s3=="09") st1=9;
	else if(s3=="10") st1=10;
	else if(s3=="11") st1=11;
	else if(s3=="12") st1=12;
	else if(s3=="13") st1=13;
	else if(s3=="14") st1=14;
	else if(s3=="15") st1=15;
	else if(s3=="16") st1=16;
	else if(s3=="17") st1=17;
	else st1=18;
	
	if(s4=="01") st2=1;
	else if(s4=="02") st2=2;
	else if(s4=="03") st2=3;
	else if(s4=="04") st2=4;
	else if(s4=="05") st2=5;
	else if(s4=="06") st2=6;
	else if(s4=="07") st2=7;
	else if(s4=="08") st2=8;
	else if(s4=="09") st2=9;
	else if(s4=="10") st2=10;
	else if(s4=="11") st2=11;
	else if(s4=="12") st2=12;
	else if(s4=="13") st2=13;
	else if(s4=="14") st2=14;
	else if(s4=="15") st2=15;
	else if(s4=="16") st2=16;
	else if(s4=="17") st2=17;
	else st2=18;
	if(che1==che2){
		ans1=1;
		if(st1==st2){
			ans2=1;
			if(h1<=3&&h2<=3){
				ans3=1;
				if(abs(h1-h2)==1){
					ans4=1;
				}
			}
			else if(h1>3&&h2>3){
				ans3=1;
				if(abs(h1-h2)==1){
					ans4=1;
				}
			}
		}
		
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
