#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2;
int s11,s22,d;
bool a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	s11=s1[0]+s1[1];
	s22=s2[0]+s2[1];
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		a=true;
	}
	else if(s1[2]=='D'||s1[2]=='F'){
		a=false; 
	} 
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		b=true;
	}
	else if(s2[2]=='D'||s2[2]=='F'){
		b=false; 
	} 
	d=s1[2]-s2[2];
	if(c1==c2){
		cout<<1;
		if(s11==s22){
			cout<<1;
			if(a==b){
				cout<<1;
				if(a==0&&b==0){
					cout<<1<<endl;
				}
				else{
					if(d==1||d==-1){
						cout<<1<<endl;
					}
					else{
						cout<<0<<endl;
					}
				}
				
			}
			else{
				cout<<0<<0<<endl;
			}
		}
		else{
			cout<<0<<0<<0<<endl;
		}
	}
	else{
		cout<<0<<0<<0<<0<<endl;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
