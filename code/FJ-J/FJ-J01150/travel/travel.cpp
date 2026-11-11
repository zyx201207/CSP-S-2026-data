#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		f1=true;
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0]&&!f1){
		cout<<1;
	}else{
		cout<<0;
		f2=true;
	}
	if(!(s1[2]=='C'&&s2[2]=='D')&&!f2){
		if(!(s1[2]=='D'&&s2[2]=='C')){
			cout<<1;
		}else{
			cout<<0;
			f3=true;
		}
	}else{
		cout<<0;
		f3=true;
	}
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
		if(f3){
			cout<<0;
		}else{
			cout<<1;
		}
	}else{
		cout<<0;
	}
	return 0;
}
