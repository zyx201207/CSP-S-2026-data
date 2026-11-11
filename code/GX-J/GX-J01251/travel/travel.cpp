#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	
	cin>>c1>>s1>>c2>>s2;
	while(1){
		if(c1[2]=='01'||c1[2]=='16'){
			cout<<"0";
		}
		else if(c1[0]==c2[0]&&c1[1]==c2[1]){
			cout<<"1";
			if(s1[0]==s2[0]&&s1[1]==s2[1]){
				cout<<"1";
				if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
					if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
						cout<<"1";
						if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
							cout<<"1";
							break;
						}
						else{
							cout<<"0";
							break;
						}
					}
					else{
						cout<<"00";
						break;
					}
				}
				else if(s1[2]=='D'||s1[2]=='F'){
					if(s2[2]=='D'||s2[2]=='F'){
						cout<<"1";
						if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
							cout<<"1";
							break;
						}
						else{
							cout<<"0";
							break;
						}
					}
					else{
						cout<<"00";
						break;
					}
				}
			}
			else{
				cout<<"000";
				break;
			}
		}
		else{
			cout<<"0000";
			break;
		}
	}
	return 0;
}
