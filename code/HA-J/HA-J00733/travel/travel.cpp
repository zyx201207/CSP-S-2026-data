#include<bits/stdc++.h>//ÎÄ¼þ²Ù×÷ 
using namespace std;
bool c[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c1,s1,c2,s2;
	string s3,s4;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		s3[i]=s1[i];
		s4[i]=s2[i];
	}
	if(c1==c2){
		c[0]=1;	
	}
	if(c[0]==1){
		if(s3[0]=='0'&&s4[0]=='0'){
			if(s3[1]==s4[1]){
				c[1]=1;
			}
		}
	}
	char a=s1[2],b=s2[2];
	if(c[0]==1&&c[1]==1){
		if(a=='A'){
			if(b=='B'||b=='C'){
				c[2]=1;
			}
		}
		if(a=='B'){
			if(b=='A'||b=='C'){
				c[2]=1;
			}
		}
		if(a=='C'){
			if(b=='A'||b=='B'){
				c[2]=1;
			} 
		}
		if(a=='D'){
			if(b=='F'){
				c[2]=1;
			}
		}
		if(a=='F'){
			if(b=='D'){
				c[2]=1;
			}
		}
	}
	if(c[0]==1&&c[1]==1){
		if(a=='A'){
			if(b=='B'){
				c[3]=1;
			}
		}
		else if(a=='B'){
			if(b=='A'||b=='C'){
				c[3]=1;
			}
		}
		else if(a=='C'){
			if(b=='B'){
				c[3]=1;
			}
		}
		else if(a=='D'){
			if(b=='F'){
				c[3]=1;
			}
		}
		else if(a=='E'){
			if(b=='F'){
				c[3]=1;
			}
		}
	}
	for(int i=0;i<=3;i++){
		cout<<c[i];
	}
	return 0;
} 
