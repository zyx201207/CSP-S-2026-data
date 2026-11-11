#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	string t1,t2;
	char r1,r2;
	t1=s1[0]+s1[1];
	t2=s2[0]+s2[1];
	if(t1==t2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	r1=s1[2];
	r2=s2[2];
	int tmp1,tmp2;
	if(r1=='A'||r1=='B'||r1=='C'){
		tmp1=0;
	}else{
		tmp1=1;
	}
	if(r2=='A'||r2=='B'||r2=='C'){
		tmp2=0;
	}else{
		tmp2=1;
	}
	if(tmp1==tmp2){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(tmp1==1){
		if(r1=='D'&&r2=='F'||r1=='F'&&r2=='D'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		if(char(int(r1)+1)==r2||char(int(r2)+1)==r1){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
}
