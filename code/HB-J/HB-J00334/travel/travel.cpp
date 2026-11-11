#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ans1=c1[0]-'0';
	int ans2=c1[1]-'0';
	int ans3=ans1*10+ans2;
	int ans4=c2[0]-'0';
	int ans5=c2[1]-'0';
	int ans6=ans4*10+ans5;
	if(ans3==ans6){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int cnt1=s1[0]-'0';
	int cnt2=s1[1]-'0';
	int cnt3=cnt1*10+cnt2;
	int cnt4=s2[0]-'0';
	int cnt5=s2[1]-'0';
	int cnt6=cnt4*10+cnt5;
	if(cnt3==cnt6){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	int f1=s1[2]-'0';
	int f2=s2[2]-'0';
	char m=s1[2];
	char n=s2[2];
	if(m=='C'&&n=='D'){
		cout<<0<<0;
		return 0;
	}
	else if(n=='C'&&m=='D'){
		cout<<0<<0;
		return 0;
	}
	else{
		if(abs(f1-f2)<=2){
			cout<<1;
			if(m=='F'&&n=='D'){
				cout<<1;
			}
			else if(m=='D'&&n=='F'){
				cout<<1;
			}
			else if(abs(f1-f2)==1){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
