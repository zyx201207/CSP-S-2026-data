#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2,ss,tt;
map<char,int>mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>t1>>t2;
	ss+=s2[0],ss+=s2[1],tt+=t2[0],tt+=t2[1];
	mp['A']=1,mp['B']=1,mp['C']=1;
	if(s1!=t1){
		cout<<"0000";
	}else if(ss!=tt){
		cout<<"1000";
	}else if(mp[s2[2]]!=mp[t2[2]]){
		cout<<"1100";
	}else if(s2[2]-1!=t2[2]&&s2[2]+1!=t2[2]){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}

