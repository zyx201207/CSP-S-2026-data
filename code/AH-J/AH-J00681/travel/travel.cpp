#include<bits/stdc++.h>
using namespace std;
bool check1(string a,string b){
	return a[0]==b[0]&&b[1]==a[1];
}
bool check2(string a,string b){
	if((a[2]<'D'&&b[2]<'D')||(a[2]>'D'&&b[2]>'D')) return 1;
	return 0;
}
bool check3(string a,string b){
	return (a[2]==b[2]+1)||(a[2]==b[2]-1);
}
int a,b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<1;
		if(check1(s1,s2)){
			cout<<1;
			if(check2(s1,s2)){
				cout<<1;
				if(check3(s1,s2)){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
