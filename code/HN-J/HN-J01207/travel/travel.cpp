#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string x="",y="";
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['F']=2;
	x+=s1[0];x+=s1[1];
	y+=s2[0];y+=s2[1];
	char a=s1[2],b=s2[2];
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else if(x!=y){
		cout<<"1000";
		return 0;
	}else if(mp[a]!=mp[b]){
		cout<<"1100";
		return 0;
	}
	cout<<"111";
	if(a=='A'){
		cout<<(b=='B');
	}if(a=='B'){
		cout<<((b=='A')||(b=='C'));
	}if(a=='C'){
		cout<<(b=='B');
	}if(a=='D'){
		cout<<(b=='F');
	}if(a=='F'){
		cout<<(b=='D');
	}
	return 0;
}
