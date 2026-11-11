#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	bool a1,a2,a3,a4;
	a1=a2=a3=a4=0;
	char w1=s2[2],w2=s4[2];
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	else{
		a1=1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			a2=1;
			if(w1>='A'&&w1<='C'&&w2>='A'&&w2<='C'){
				a3=1;
				if(w1=='A'&&w2=='B')a4=1;
				if(w1=='B'&&w2=='C')a4=1;
				if(w1=='B'&&w2=='A')a4=1;
				if(w1=='C'&&w2=='B')a4=1;
			}
			if(w1=='D'&&w2=='F')a3=a4=1;
			if(w1=='F'&&w2=='D')a3=a4=1;
		}
		cout<<a1<<a2<<a3<<a4;
	}
	return 0;
}
