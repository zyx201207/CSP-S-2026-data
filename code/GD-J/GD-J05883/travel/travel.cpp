#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool qq_b1=0,qq_b2=0,qq_b3=0,qq_b4=0;
	string qq_c1;
	string qq_c2;
	string qq_s1;
	string qq_s2;
	cin>>qq_c1>>qq_s1>>qq_c2>>qq_s2;
	
	if(qq_c1==qq_c2) {
		qq_b1=1;
	}
	
	if(qq_s1[0]==qq_s2[0]&&qq_s1[1]==qq_s2[1]){
		qq_b2=1;
	}
	
	bool qq_t1=0,qq_t2=0;
	if(qq_s1[2]=='A'||qq_s1[2]=='B'||qq_s1[2]=='C') qq_t1=1;
	if(qq_s1[2]=='D'||qq_s1[2]=='F') qq_t2=1;
	if(qq_s2[2]=='A'||qq_s2[2]=='B'||qq_s2[2]=='C') qq_t1=1;
	if(qq_s2[2]=='D'||qq_s2[2]=='F') qq_t2=1;
	if(qq_t1+qq_t2==1) qq_b3=1;
	
	if(qq_s1[2]=='A'&&qq_s2[2]=='B'||qq_s1[2]=='B'&&qq_s2[2]=='C'||qq_s1[2]=='D'&&qq_s2[2]=='F') qq_b4=1;
	if(qq_s1[2]=='B'&&qq_s2[2]=='A'||qq_s1[2]=='C'&&qq_s2[2]=='B'||qq_s1[2]=='F'&&qq_s2[2]=='D') qq_b4=1;
	
	
	cout<<qq_b1;
	if(qq_b1==1) cout<<qq_b2;
	else cout<<0;
	if(qq_b1==1&&qq_b2==1) cout<<qq_b3;
	else cout<<0;
	if(qq_b1==1&&qq_b2==1&&qq_b3==1) cout<<qq_b4;
	else cout<<0; 
	return 0;
}
	
