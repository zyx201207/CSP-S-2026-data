#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long n1,n2;
string s1,s2;
bool st(){
	if(n1==n2)return true;
	return false;
}
bool sp(){
	if(s1[0]==s2[0]&&s1[1]==s2[1])return true;
	return false;
}
bool sc(){
	if(s1[2]>='A'&&s1[2]<='C'){
		if(s2[2]>='A'&&s2[2]<='C'){
			return true;
		}
	}
	if(s1[2]>='D'&&s1[2]<='E'){
		if(s2[2]>='D'&&s2[2]<='E'){
			return true;
		}
	}
	return false;
}
bool xl(){
	if((int)s1[2]+1==s2[2]||(int)s1[2]-1==s2[2])return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n1>>s1>>n2>>s2;
	if(st()){
		cout<<1;
		if(sp()){
			cout<<1;
			if(sc()){
				cout<<1;
				if(xl()){
					cout<<1;
				}else{
					cout<<0;
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
