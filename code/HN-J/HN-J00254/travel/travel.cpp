#include<bits/stdc++.h>
using namespace std;
string a,b,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='D'){
		if(s2[2]=='F'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else if(s1[2]=='F'){
		if(s2[2]=='D'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else if(s2[2]=='D'){
		if(s1[2]=='F'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else if(s2[2]=='F'){
		if(s1[2]=='D'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		cout<<"1";
	}
	int x=s1[2]-'A',y=s2[2]-'A';
	if(abs(x-y)==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
