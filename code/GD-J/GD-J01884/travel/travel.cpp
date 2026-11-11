#include<bits/stdc++.h>
using namespace std;
typedef string str;
str c1,s1,c2,s2;
bool is_j(){
	return c1==c2;
}
int is_p(){
	if(is_j()==1){
		int sx1=(s1[0]-'0')*10+(s1[1]-'0');
		int sx2=(s2[0]-'0')*10+(s2[1]-'0');
		return sx1==sx2;
	}
	return 0;
}
bool is_c(){
	if(is_p()){
		char sz1=s1[2];
		char sz2=s2[2];
		if(sz1<='C' && sz2<='C'){
			return 1;
		}else if(sz1>='D' && sz2>='D'){
			return 1;
		}else{
			return 0;
		}
	}
}
bool is_x(){
	if(is_c()){
		int sz1=s1[2];
		int sz2=s2[2];
		if(abs(sz1-sz2)==1){
			return 1;
		}
		return 0;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<is_j()<<is_p()<<is_c()<<is_x();
	return 0;
} 
