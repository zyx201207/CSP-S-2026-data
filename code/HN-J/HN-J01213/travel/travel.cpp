#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int len=s1.size(),len1=s2.size(),len2=c1.size(),len3=c2.size();
	if(c1[len2]!='0'&&c1[len2]!='1'||c2[len3]!='0'&&c2[len3]!='1'||c1[len2]!='1'&&c1[len2]!='6'||c2[len3]!='1'&&c2[len3]!='6'){
	
	if(c1[len2-2]==c2[len3-2]&&c1[len2-1]==c2[len3-1]) {
			cout<<"1";
		} else {
			cout<<"0";
		}
	if(s1[len-2]==s2[len1-2]&&s1[len-3]==s2[len1-3]&&c1[len2-2]==c2[len3-2]&&c1[len2-1]==c2[len3-1]) {
		cout<<"1";
	} else {
		cout<<"0";
	}
	if(c1[len2-2]==c2[len3-2]&&c1[len2-1]==c2[len3-1]&&s1[len-3]==s2[len1-3]&&s1[len-2]==s2[len1-2]&&s1[len-1]=='F'&&s2[len1-1]=='D'||s1[len-1]=='D'&&s2[len-1]=='F') {
		cout<<"1";
	} else if(c1[len2-2]==c2[len3-2]&&c1[len2-1]==c2[len3-1]&&s1[len1-1]=='A'&&s2[len1-1]=='B'||s1[len-1]=='B'&&s2[len1-1]=='C'||s1[len-1]=='C'&&s2[len1-1]=='A'&&s1[len-1]!=s2[len1-1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1[len2-2]==c2[len3-2]&&c1[len2-1]==c2[len3-1]&&s1[len-1]-'A'+1==s2[len-1]-'A') {
		if(c1[len2-2]==c2[len3-2]&&c1[len2-1]==c2[len3-1]&&s1[len-1]=='C'&&s2[len1-1]=='D'||s1[len-1]=='D'&&s2[len1-1]=='C'){
			cout<<"0";
		}else{
			cout<<"1";
		}
		}else{
			cout<<"0";
		}
	} else {
		cout<<"0";
	}
	return 0;
}
