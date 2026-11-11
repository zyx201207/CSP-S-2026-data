#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
char c3,c4;
int ans1,ans2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2) cout<<"0000";
	else{
		cout<<"1";
		c3=c1[2],c4=c2[2];
		ans1=(c1[0]-'0')*10+(c1[1]-'0');
		ans2=(c2[0]-'0')*10+(c2[1]-'0');
		if(ans1==ans2){
			cout<<"1";
			if((c3<='C'&&c4<='C')||(c3>='D'&&c4>='D')){
				cout<<"1";
				if(c3+1==c4||c3-1==c4) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		} 
		else cout<<"000";
	} 
	return 0;
}
