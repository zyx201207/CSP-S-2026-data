#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ar[10][30] = {},a,b;
string s1,s2;
int func(string x){
	return (x[0]-'0')*10 + (x[1]-'0');
}
int func1(char c){
	switch(c){
		case 'A':return 1;
		case 'B':return 2;
		case 'C':return 3;
		case 'D':return 5;
		case 'F':return 6; 
	}
}
bool judge(int x,int y){
	if(x<=3&&y<=3&&x!=y)return 1;
	else if(x>4&&y>4&&x!=y)return 1;
	else return 0;
}
int main(){
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<"1";
		if(func(s1)==func(s2))cout<<"1";
		else{
			cout<<"000";
			return 0;
		}
		int m = func1(s1[2]),n = func1(s2[2]);
		if(judge(m,n))cout<<"1";
		else{
			cout<<"00";
			return 0;
		}
		if(m+1==n||m-1==n)cout<<"1";
		else cout<<"0";
	}else cout<<"0000";
	return 0;
}

