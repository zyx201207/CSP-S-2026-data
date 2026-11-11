#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2,ans="0000";
map<char,int>s,pos;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	s['A']=s['B']=s['C']=1,s['D']=s['F']=2;
	pos['A']=1,pos['B']=2,pos['C']=3,pos['D']=5,pos['F']=6;
	if(a1==b1){
		ans[0]='1';
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			ans[1]='1';
			if(s[a2[2]]==s[b2[2]])ans[2]='1';
			if(abs(pos[a2[2]]-pos[b2[2]])==1)ans[3]='1';
		}
	}
	cout<<ans;
	return 0;
}
