//GZ-J00630 张庭赫 贵阳中天中学 
#include<bits/stdc++.h>
using namespace std;
string check1(string a){
	string n;
	for(char x:a){
		if(x=='0' || x=='1' || x=='2' || x=='3' || x=='4' || x=='5' || x=='6' || x=='7' || x=='8' || x=='9' ) n+=x;
	}
	return n;
} 

long long check2(string a){
	long long n;
	for(char x:a){
		if(x=='A' || x=='B' || x=='C' ) n=1;
		if(x=='D' || x=='F' ) n=0;
	}
	return n;
} 

long long check3(string a){
	long long n;
	for(char x:a){
		if(x=='A') n=1;
		if(x=='B') n=2;
		if(x=='C') n=3;
		if(x=='D') n=5;
		if(x=='F') n=6;
	}
	return n;
} 

int main(){
	#define int long long
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(check1(s1)==check1(s2)){
			if(check2(s1)==check2(s2)){
				if(abs(check3(s1)-check3(s2))==1) cout<<"1111";
				else							  cout<<"1110";
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
