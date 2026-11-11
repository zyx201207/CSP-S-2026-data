#include<bits/stdc++.h>
using namespace std;
int m[105],n[105];
int s1=0,s2=0;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b[2]=='A'){
			s1=1;
	}
	if(b[2]=='B'){
			s1=2;
	}
	if(b[2]=='C'){
			s1=3;
	}
	if(b[2]=='D'){
			s1=4;
	}
	if(b[2]=='F'){
			s1=5;
	}
	if(d[2]=='A'){
			s2=1;
	}
	if(d[2]=='B'){
			s2=2;
	}
	if(d[2]=='C'){
			s2=3;
	}
	if(d[2]=='D'){
			s2=4;
	}
	if(d[2]=='F'){
			s2=5;
	}
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				m[1]=1;
			}
			else{
				m[1]=0;
			}
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				n[1]=1;
			}
			else{
				n[1]=0;
			}
			if(m[1]==n[1]){
				cout<<"1";
				if((s1-s2)==-1||(s1-s2)==1||(s1-s2)==0){
					cout<<"1";
					return 0;
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
