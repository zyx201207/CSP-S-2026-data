#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b){
	if('A'<=a&&'C'>=a)
		if('A'<=b&&'C'>=b)return 1;
		else return 0;
	else 
		if('A'<=b&&'C'>=b)return 0;
		else return 1;
}
bool s(string a,string b){
	if(a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2])return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1,s2;
	//ios::sync_studio(false)
	cin>>c1>>s1>>c2>>s2;
	//cout<<c1<<c2;
	if(s(c1,c2)){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(check(s1[2],s2[2])){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
		
	}
	else cout<<"0000";
	return 0;
}
