#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a[4];
bool f(char a,char b){
	if(a>='A'&&a<='C'){
		if(b>='A'&&b<='C'){
			return 1;
		}else{
			return 0;
		}
	}else{
		if(b=='D'||b=='F'){
			return 1;
		}else{
			return 0;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)a[0]=1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a[1]=1;
	}else{
		cout<<"1000";
		return 0;
	}
	if(f(s1[2],s2[2])){
		a[2]=1;
	}else{
		cout<<"1100";
		return 0;
	}
	if(s1[2]=='D'||s1[2]=='F'){
		cout<<"1111";
	}else if(s1[2]=='B'||s2[2]=='B'){
		cout<<"1111";
	}else{
		cout<<"1110";
	}
	return 0;
} 
