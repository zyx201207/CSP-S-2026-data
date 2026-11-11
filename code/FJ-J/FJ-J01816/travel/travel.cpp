#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		 cout<<"1";
		 if(s1[0]==s2[0]&&s1[1]==s2[1]){
		 	cout<<"1";
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				cout<<"1";
				int a=s1[2],b=s2[2];
				if(s2[2]=='F'&&s1[2]=='D') cout<<"1";
				else if(s1[2]=='F'&&s2[2]=='D') cout<<"1";
				else if(abs(a-b)==1) cout<<"1";
				else cout<<"0";
			} 
			else cout<<"00";
		 } 
		 else cout<<"000";
		 
	}
	else cout<<"0000";

	return 0;
}
