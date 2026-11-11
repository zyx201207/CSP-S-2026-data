#include <bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
bool flag;
bool check1(){
	int r=(r1[0]-'0')*10+(r1[1]-'0');
	int x=(x1[0]-'0')*10+(x1[1]-'0');
	if(r==x) return 1;
	return 0;
}
bool check2(){
	int r=(r2[0]-'0')*10+(r2[1]-'0');
	int x=(x2[0]-'0')*10+(x2[1]-'0');
	if(r==x) return 1;
	return 0;
}
bool check3(){
	if(r2[2]>='A' && r2[2]<='C' && x2[2]>='A' && x2[2]<='C'){
		flag=0;
		return 1;
	}else if(r2[2]>='D' && r2[2]<='F' && x2[2]>='D' && x2[2]<='F'){
		flag=1;
		return 1;
	}else{
		return 0;
	}
}
bool check4(){
	if((!flag && abs(r2[2]-x2[2])==1) || flag) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(check1()){
		cout<<'1';
		if(check2()){
			cout<<'1';
			if(check3()){
				cout<<'1';
				if(check4()){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
