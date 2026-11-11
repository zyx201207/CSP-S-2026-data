#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1="",s2="";
	bool v=1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<3;i++){
			if(s1[i]==s2[i]){
				if(v==1 &&i==1)cout<<1;
			}
			else if(i==2){
				if(s1[i]=='A'||s1[i]=='B'||s1[i]=='C'){
					if(s2[i]=='A'||s2[i]=='B'||s2[i]=='C'){
						cout<<1;
						if(s1[i]=='A'){
							if(s2[i]=='B')cout<<1;
							else cout<<0;
						}
						if(s1[i]=='B'){
							if(s2[i]=='A'||s2[i]=='C')cout<<1;
							else cout<<0;
						}
						if(s1[i]=='C'){
							if(s2[i]=='B')cout<<1;
							else cout<<0;
						}
					}
					else cout<<0<<0;
				}
				else if(s1[i]=='D'||s1[i]=='F'){
					if(s2[i]=='D'||s2[i]=='F'){
						cout<<1;
						if(s1[i]=='D'){
							if(s2[i]=='F')cout<<1;
							else cout<<0;
						}
						if(s1[i]=='F'){
							if(s2[i]=='D')cout<<1;
							else cout<<0;
						}
					
					}
					else cout<<0<<0;
				}
				
			}
			else {
				v=0;
				cout<<0<<0<<0;
				break;
			}
		}
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
