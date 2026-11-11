#include <bits/stdc++.h> 
using namespace std;

bool check1(char ch1,char ch2){
	if(ch1-'A' <= 2 && ch2-'A' <=2) return true;
	else if(ch1-'A' > 2 && ch2-'A' >2) return true;
	return false;
}

int trans(char ch1){
	if(ch1=='F') return 5;
	return ch1-'A'+1;
}

bool check2(char ch1,char ch2){
	if(abs(trans(ch1)-trans(ch2))==1) return true;
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);//文件IO 
	string c1,c2;//车厢号 
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}//车厢号不同，后面的条件也不满足 
	if(s1.substr(0,2)!=s2.substr(0,2)){
		cout<<"1000";
		return 0;
	}//不在同一排 
	bool flag=check1(s1[2],s2[2]);
	if(!flag){
		cout<<"1100";
		return 0;
	}//不在过道同一侧 
	if(!check2(s1[2],s2[2])){
		cout<<"1110";//不相邻 
	}else{
		cout<<"1111";//相邻 
	}
	return 0;
}
