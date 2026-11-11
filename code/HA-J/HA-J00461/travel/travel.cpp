#include<bits/stdc++.h>
using namespace std;
bool check(char _,char __){
	if(_=='A'||_=='B'||_=='C'){
		if(__=='A'||__=='B'||__=='C')return 1;
		else return 0;
	}if(_=='D'||_=='E'){
		if(__=='D'||__=='E')return 1;
		else return 0;
	}
}bool checkk(char _,char __){
	if(int(_)==int(__)+1||int(__)==int(_)+1)return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char cs1,cs2;
	cin>>c1>>s1>>cs1>>c2>>s2>>cs2;
	cout<<(c1==c2)<<(c1==c2&&s1==s2)<<(c1==c2&&s1==s2&&check(cs1,cs2))<<((c1==c2&&s1==s2&&check(cs1,cs2))&&checkk(cs1,cs2));
	return 0;
}
