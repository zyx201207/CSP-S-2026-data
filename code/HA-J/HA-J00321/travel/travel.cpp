#include<bits/stdc++.h>
using namespace std;

bool pan(string s1,string s2){
	if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='B' && s1[2]=='A') || (s2[2]=='B' && s1[2]=='C')){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		string ss="0000";
		cout<<ss;
		return 0;
	} 
	bool b2=false;
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
		b2=true;
	}else{
		string sss="000";
		cout<<sss;
		return 0;
	}
	int a=0,b=0;//表示第1,2部分 
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
		a=1;
	}else{
		a=2;
	}
	if(s2[2]=='D' || s2[2]=='F'){
		b=2;
	}else{
		b=1;
	}
	if(b2==true && a==b){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a!=b){
		cout<<0;//先把不在同一个部分的删除 
		return 0;
	}
	if(a==b){
		if(a==2){
			cout<<1;
			return 0;
		}else{
			if(pan(s1,s2)==true){
				cout<<1;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}
	}
}


