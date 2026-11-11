#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<"1";
		if(c2[0]==s2[0]&&c2[1]==s2[1])
		{
			cout<<"1";
			bool x_1=0,x_2=0;
			if(c2[2]=='D'||c2[2]=='F') x_1=1;
			if(s2[2]=='D'||s2[2]=='F') x_2=1;
			if(x_1==x_2){
				cout<<"1";
				if(x_1&&x_2) cout<<"1";
				else if(c2[2]=='B'||s2[2]=='B') cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
} 
