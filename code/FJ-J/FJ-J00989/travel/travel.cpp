#include<bits/stdc++.h>
using namespace std;

int main()

{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string s1pai="",s2pai="";
	char s1wei,s2wei;
	cin>>c1>>s1>>c2>>s2;
	for(int i = 0;i<3;i++){
		if(i==1 || i==0){
			s1pai+=s1[i];
			s2pai+=s2[i];
		}
		else{
			s1wei=s1[i];
			s2wei=s2[i];
		}
	}
	int s1s=s1wei-'A';
	int s2s=s2wei-'A';
	if(c1==c2){
		cout<<"1";
		if(s1pai==s2pai){
			cout<<"1";
			if(s1wei=='A' || s1wei=='B' || s1wei=='C'){
				if(s2wei=='A' || s2wei=='B' || s2wei=='C'){
					cout<<"1";
					if(s1s>s2s){
						if(s1s-s2s==1){
							cout<<"1";
						}
						else{
							cout<<"0";
						}
					}
					else if(s2s>s1s){
						if(s2s-s1s==1){
							cout<<"1";
						}
						else{
							cout<<"0";
						}
					}	
				}
				else{
					cout<<"00";
				}
			}
			else if(s1wei=='D' ||s1wei=='F'){
				if(s2wei=='D' || s2wei=='F'){
					cout<<"11";
				}
				else{
					cout<<"00";
				}
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
