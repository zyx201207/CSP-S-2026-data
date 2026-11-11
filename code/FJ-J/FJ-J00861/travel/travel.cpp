#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	bool f1=0,f2=0;
	if(c1[2]=='D'||c1[2]=='F'){
		f1=1;
	}
	if(c2[2]=='D'||c2[2]=='F'){
		f2=1;
	}
	if(f1==f2){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(c1[2]=='B'||c2[2]=='B'||f1){
		cout<<1;
	}else {
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
