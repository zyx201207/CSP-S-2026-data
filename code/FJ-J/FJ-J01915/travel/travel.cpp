#include<bits/stdc++.h>
using namespace std;

string c_1,c_2;	//车厢号 
string s_1,s_2;	//座位号 

bool f_1(){
	if(c_1==c_2){	//在同一车厢 
		return 1;
	}
	return 0;
}

bool f_2(){
	
	if(!f_1())return 0;
	
	if(s_1[1]==s_2[1] && s_1[0]==s_2[0]){
		return 1;	//头两位相等说明在同一排 
	}
	return 0;
}

bool f_3(){
	
	if(!f_2())return 0;
	
	if(s_1[2]=='A'){
		if(s_2[2]=='B'||s_2[2]=='C'){
			return 1;
		}
	}else if(s_1[2]=='B'){
		if(s_2[2]=='A'||s_2[2]=='C'){
			return 1;
		}
	}else if(s_1[2]=='C'){
		if(s_2[2]=='A'||s_2[2]=='B'){
			return 1;
		}
	}else if(s_1[2]=='D'){
		if(s_2[2]=='F'){
			return 1;
		}
	}else if(s_1[2]=='F'){
		if(s_2[2]=='D'){
			return 1;
		}
	}
	return 0;
}

bool f_4(){
	if(!f_3())return 0;
	
	if(s_1[2]-1==s_2[2] || s_1[2]+1==s_2[2]){
		return 1;
	}
	return 0;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>c_1>>s_1>>c_2>>s_2;
	
	cout<<f_1()<<f_2()<<f_3()<<f_4();
	
	return 0;
}
