#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,ans;
bool v[6][6]{
	{0,1,0,0,0,0},
	{1,0,1,0,0,0},
	{0,0,1,0,0,0},
	{0,0,0,0,0,1},
	{0,0,0,1,0,0}
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		ans+='1';
		if(s2.substr(0,2)==s4.substr(0,2)){
			ans+='1';
			int x=s2.back()-'A',y=s4.back()-'A';
			if((x<3&&y<3)||(x>=3&&y>=3)){
				ans+='1';
				if(v[x][y])
					ans+='1';
				else
					ans+='0';
			}
			else
				ans+="00";
		}
		else
			ans+="000";
	}
	else
		ans="0000";
	cout<<ans<<'\n';
	return 0;
}
