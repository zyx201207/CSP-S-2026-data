#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
void _travel(){
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(
	(s1[2]==s2[2]-1&&s1[2]!='C')||
	(s1[2]==s2[2]+1&&s1[2]!='D'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&
	(
	(s1[2]=='A'&&s2[2]=='B')||
	(s1[2]=='B'&&s2[2]=='C')||
	(s1[2]=='B'&&s2[2]=='A')||
	(s1[2]=='C'&&s2[2]=='B')||
	(s1[2]=='D'&&s2[2]=='E')||
	(s1[2]=='E'&&s2[2]=='D')
	)
	)
	{
		cout<<"1";
	}else{
		cout<<"0";
	}
	cout<<endl; 
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
//	cin>>t;
	while(T--){
		_travel();
	}
	return 0; 
}
