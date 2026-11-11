#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool t1=0,t2=0,t3=0,t4=0;
	if(c1==c2){
		t1 = 1;
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(t1==1){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			t2=1;
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	if(t2==1){
		if(s1[2]=='F'||s1[2]=='D'){
			if(s2[2]=='F'||s2[2]=='D'){
				t3 = 1;
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				t3 = 1;
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	}
	else{
		cout<<0;
	}
	if(t3==1){
		if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
}
