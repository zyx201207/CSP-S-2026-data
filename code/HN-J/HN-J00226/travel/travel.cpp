#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool check1(string a,string b){
	bool f1;
	if(a[2]=='F'||a[2]=='D')f1=true;
	else f1=false;
	bool f2;
	if(b[2]=='F'||b[2]=='D'){
		f2=true;
	}
	else f2=false;
	if(f1==f2)return true;
	else return false;
}
bool check2(char a,char b){
	int l=(a-'A'),r=(b-'A');
	if(abs(l-r)==1){
		return true;
	}
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)cout<<"1";
	else{
		cout<<"0000\n";
		return 0;
	}
	int t1=(c2[0]-'0')*10+(c2[1]-'0');
	int t2=(s2[0]-'0')*10+(s2[1]-'0');
	if(t1==t2)cout<<"1";
	else{
		cout<<"000\n";
		return 0;
	}
	if(check1(c2,s2)){
		cout<<"1";
	}
	else{
		cout<<"00\n";
		return 0;
	}
	if(check2(c2[2],s2[2])){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
} 
