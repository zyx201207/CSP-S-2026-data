#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1,s2;
	int x=4;
	cin>>c1>>s1>>c2>>s2;
	int a1=s1[0]*10+s1[1];
	int a2=s2[0]*10+s2[1];
	if(c1==c2){
		cout<<"1";
		x--;
		if(a1==a2){
		cout<<"1";	
		x--;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					cout<<"1";
					x--;
					if(s1[2]=='A'&&s2[2]=='B'){
						cout<<"1";
						x--;
					} 
						if(s1[2]=='B'&&s2[2]=='C'){
						cout<<"1";
						x--;
					}
						if(s1[2]=='B'&&s2[2]=='A'){
						cout<<"1";
						x--;
					}
						if(s1[2]=='C'&&s2[2]=='B'){
						cout<<"1";
						x--;
					}
				}
			}
			if(s1[2]=='F'||s1[2]=='D'){
				if(s2[2]=='F'||s2[2]=='D'){
					cout<<"1";
					x--;
						if(s1[2]=='F'&&s2[2]=='D'){
						cout<<"1";
						x--;
					}
						if(s1[2]=='D'&&s2[2]=='F'){
						cout<<"1";
						x--;
					}
				}
			}
		}	
	}
	for(int i=1;i<=x;i++){
		cout<<"0";
	}
	return 0;
}
