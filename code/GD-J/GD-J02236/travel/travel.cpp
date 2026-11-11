#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	int x=s2[2]-'A'+1;
	int y=s4[2]-'A'+1;
	if((x>=4&&y>=4)||(x<4&&y<4)){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(x<4&&y<4){
		if(abs(s2[2]-s4[2])==1)cout<<1;
		else cout<<0;
	}else{
		if(abs(s2[2]-s4[2])==2)cout<<1;
		else cout<<0;
	}
	return 0;
}
