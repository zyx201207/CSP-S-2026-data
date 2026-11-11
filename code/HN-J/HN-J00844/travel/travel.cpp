#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
bool f(char a,char b){
	int c=a-'A'+1,d=b-'A'+1;
	if((c<=3&&d<=3)||(c>3&&d>3)){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<'1';
		if(s[0]==ss[0]&&s[1]==ss[1]){
			cout<<'1';
			if(f(s[2],ss[2])){
				cout<<'1';
				if(s[2]-'0'-1==ss[2]-'0'||ss[2]-'0'-1==s[2]-'0'){
					cout<<'1';
				}else cout<<'0';
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
 
