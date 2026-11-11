#include<bits/stdc++.h>
using namespace std;
bool w1,w2,w3,w4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	//1
	if(c1==c2)w1=1;
	else w1=0;
	//2
	string Q1=s1.substr(0,2);
	string Q2=s2.substr(0,2);
	if(Q1==Q2&&w1)w2=1;
	else w2=0;
	//3
	char P1=s1[2];
	char P2=s2[2];
	char H1[7]={'A','B','C'};
	char H2[7]={'D','F'};
	int t1=1,t2=1;
	for(int i=0;i<=2;i++){
		if(P1==H1[i])t1=2;
		if(P2==H1[i])t2=2;
	}if(t1==t2&&w2)w3=1;
	else w3=0;
	//4
	if(P1=='A')if(P2=='B')if(w3)w4=1;
	if(P1=='B')if(P2=='A'||P2=='C')if(w3)w4=1;
	if(P1=='C')if(P2=='B')if(w3)w4=1;
	if(P1=='D')if(P2=='F')if(w3)w4=1;
	if(P1=='F')if(P2=='D')if(w3)w4=1;
	//res
	cout<<w1<<w2<<w3<<w4;
	return 0;
} 
