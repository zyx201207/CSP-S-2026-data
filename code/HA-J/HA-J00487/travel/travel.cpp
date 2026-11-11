#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	
	
	
	if(c1==c2){
		
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				
					if(s1[2]=='A'&&s2[2]=='B'){
						cout<<"1111";
						return 0;
					}
					if(s1[2]=='B'&&s2[2]=='A'){
						cout<<"1111";
						return 0;
					}
					if(s1[2]=='B'&&s2[2]=='C'){
						cout<<"1111";
						return 0;
					}
					if(s1[2]=='C'&&s2[2]=='B'){
						cout<<"1111";
						return 0;
					}
					else {
						cout<<"1110";
						return 0;
					}
				}
				else{
					cout<<"1100";
					return 0;
				}
			}
			if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='D'||s2[2]=='F'){
					cout<<"1111";
				}
					else{
					cout<<"1100";
					return 0;
				}
			}
		}
		else{
			cout<<"1000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
