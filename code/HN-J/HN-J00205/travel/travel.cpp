#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//1
	if(c1==c2) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	//2
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	//3
	if((s1[2]+s2[2]<='B'+'C')||(s1[2]+s2[2]=='D'+'E'))
		cout<<1;
	else{cout<<"00";
		return 0;
	}
	
	//4
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
		if(s1[2]+s2[2]=='D'+'C') cout<<0;
		else cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
} 
