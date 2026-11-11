#include <bits/stdc++.h>
using namespace std;
bool f(string s1,string s2){
	if (s1[0]==s2[0]){
		if (s1[1]==s2[1]){
			return true;
		}
	}
	return false;
}
bool g(char c,char d){
	int a=c,b=d;
	if ((a>=65&&a<=67)&&(b>=65&&b<=67)||(a>=68&&a<=70)&&(b>=68&&b<=70)){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char c=s1[2],d=s2[2];
	if (c1==c2){
		cout<<"1";
		if (f(s1,s2)){
			cout<<"1";
			if (g(c,d)){
				cout<<"1";
				if (c+1==d||c-1==d){
					cout<<"1";
				}else  cout<<"0";
			}else  cout<<"00";
		}else  cout<<"000";
	}else  cout<<"0000";
	return 0;
}
