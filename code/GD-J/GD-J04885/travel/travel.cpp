#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
string c1,c2,s1,s2;
bool check1(){
	if(c1==c2){
		return true;
	}else{
		return false;
	}
}
bool check2(){
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]){
			return false;
		}
	}
	if(check1()){
		return true;
	}else{
		return false;
	}
}
bool check3(){
	if(check2()){
		if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C')) return true;
		if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')) return true;
		if(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B')) return true;
		if(s1[2]=='D'&&s2[2]=='F') return true;
		if(s1[2]=='F'&&s2[2]=='D') return true;
	}
	return false;
}
bool check4(){
	if(check3()&&(s1[2]-1==s2[2]||s1[2]+1==s2[2])){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	cout<<check1()<<check2()<<check3()<<check4();
	return 0;
} 
