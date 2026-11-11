#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			bool p1,p2;
			if('A'<=s1[2]&&s1[2]<='C'){
				p1=1;
			}
			else{
				p1=0;
			}
			if('A'<=s2[2]&&s2[2]<='C'){
				p2=1;
			}
			else{
				p2=0;
			}	
			if(p1==p2){
				cout<<1;
				if(p1==0){
					cout<<1;
				}
				else{
					if(s1[2]=='B'||s2[2]=='B'){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
			}		
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	return 0;
}
