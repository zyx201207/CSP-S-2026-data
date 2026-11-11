#include<bits/stdc++.h>
using namespace std;
string s1,s2,ss1,ss2;
bool flag1,flag2,flag3,flag4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>ss1>>s2>>ss2;
	if(s1==s2){
		flag1=1;
		if(ss1[0]==ss2[0] && ss1[1]==ss2[1]){
			flag2=1;
			if(ss1[2]=='A' && ss2[2]=='B' || ss1[2]=='B' && ss2[2]=='A' || ss1[2]=='A' && ss2[2]=='C' || ss1[2]=='C' && ss2[2]=='A' || ss1[2]=='B' && ss2[2]=='C' || ss1[2]=='C' && ss2[2]=='B' || ss1[2]=='D' && ss2[2]=='F' || ss1[2]=='F' && ss2[2]=='D'){
				flag3=1;
				if(ss1[2]=='A' && ss2[2]=='B' || ss1[2]=='B' && ss2[2]=='A' || ss1[2]=='B' && ss2[2]=='C' || ss1[2]=='C' && ss2[2]=='B' || ss1[2]=='D' && ss2[2]=='F' || ss1[2]=='F' && ss2[2]=='D'){
					flag4=1;
				}
			}
		}
	}
	if(flag1){
		cout<<1;
	}else{
		cout<<0;
	}
	if(flag2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(flag3){
		cout<<1;
	}else{
		cout<<0;
	}
	if(flag4){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
