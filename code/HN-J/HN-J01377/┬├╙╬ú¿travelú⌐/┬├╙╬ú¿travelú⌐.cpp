#include<bits/stdc++.h>
using namespace std;
string r2,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int r1=s1.size()-1;
	int x1=s2.size()-1;
	for(int i=0;i<s1.size()-1;i++){
		r2=s1[i]+r2;
	}
	for(int i=0;i<s2.size()-1;i++){
		x2=s2[i]+x2;
	}
	if(c1==c2){
	cout<<"1";
		if(r2==x2){
			cout<<"1";
			if(s1[r1]=='A'||s1[r1]=='B'||s1[r1]=='C'){
				if(s2[x1]=='A'||s2[x1]=='B'||s2[x1]=='C'){
					cout<<"1";
					if(s1[r1]=='A'&&s2[x1]=='B') cout<<"1";
					if(s1[r1]=='B'&&s2[x1]=='C') cout<<"1";
					if(s1[r1]=='C'&&s2[x1]=='b') cout<<"1";
				}
			}
			if(s1[r1]=='D'||s1[r1]=='E'){
				if(s2[x1]=='D'||s2[x1]=='E'){
					cout<<"1";
					if(s1[r1]=='D'&&s2[x1]=='E') cout<<"1";
					if(s1[r1]=='E'&&s2[x1]=='D') cout<<"1";
				}
			}
		}
	}
	return 0;
}
