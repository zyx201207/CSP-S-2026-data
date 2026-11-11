#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
bool check_one(){
	if(cr==cx)return true;
	return false;
}
bool check_two(){
	if(check_one()&&sr[0]==sx[0]&&sr[1]==sx[1])return true;
	return false;
}
bool check_three(){
	if(check_two()){
		if(sr[2]>='A'&&sr[2]<='C'&&sx[2]>='A'&&sx[2]<='C')return true;
		if(sr[2]>='D'&&sr[2]<='F'&&sx[2]>='D'&&sx[2]<='F')return true;
	}
	return false;
}
bool check_four(){
	if(check_three()){
		if(sr[2]>='A'&&sr[2]<='B'&&sx[2]>='A'&&sx[2]<='B')return true;
		if(sr[2]>='B'&&sr[2]<='C'&&sx[2]>='B'&&sx[2]<='C')return true;
		if(sr[2]>='D'&&sr[2]<='F'&&sx[2]>='D'&&sx[2]<='F')return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>cr>>sr>>cx>>sx;
	cout<<check_one();
	cout<<check_two();
	cout<<check_three();
	cout<<check_four();
	return 0;
}
