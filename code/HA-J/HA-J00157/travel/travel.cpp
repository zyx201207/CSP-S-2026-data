#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1!=c_2)cout<<"0000\n";
	else{
		if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]){
			cout<<"11";
			a=max(s_1[2],s_2[2]),b=min(s_2[2],s_1[2]);
			if(a=='A'||a=='D')cout<<"00\n";
			else if((int)(a-b)==1)cout<<"11\n";
			else cout<<"10\n";
		}else cout<<"1000\n";
	}
	return 0;
}
