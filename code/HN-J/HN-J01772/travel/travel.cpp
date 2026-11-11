#include<bits/stdc++.h>
using namespace std;
long long cx1,cx2,bh1,bh2;
char a1,a2;
int q1=0,q2=0,q3=0,q4=0,pda,pdb;
string b; 
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>cx1>>b;
	bh1=(b[0]-'0')*10;
	bh1=bh1+(b[1]-'0');
	a1=b[2];
	cin>>cx2>>b;
	bh2=(b[0]-'0')*10;
	bh2=bh2+(b[1]-'0');
	a2=b[2];
	if (cx1==cx2)q1=1;
	if ((bh1==bh2)&& q1==1)q2=1;
	if (a1=='F' || a1=='D')pda=1;
	if (a1=='A' || a1=='B' || a1=='C')pda=2;
	if (a2=='F' || a2=='D')pdb=1;
	if (a2=='A' || a2=='B' || a2=='C')pdb=2;
	if ((pda==pdb)&& q2==1)q3=1;
	if ((a1==a2-1 || a2==a1-1) && q3==1)q4=1;
	cout<<q1<<q2<<q3<<q4;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
