#include<bits/stdc++.h>
using namespace std;
int rc,xc,rz,xz;
char rs,xs;
char a[3];
bool t1,t2,t3,t4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc;
	cin>>a;
	rs=a[2];
	rz=10*(a[0]-'0')+a[1]-'0';
	cin>>xc;
	cin>>a;
	xs=a[2];
	xz=10*(a[0]-'0')+a[1]-'0';
	t1=(rc==xc);
	cout<<t1;
	if(t1)t2=(rz==xz);
	else t2=0;
	cout<<t2;
	if(t2){
		if((rs=='A'||rs=='B'||rs=='C')&&(xs=='A'||xs=='B'||xs=='C'))t3=1;
		else if((rs=='D'||rs=='F')&&(xs=='D'||xs=='F'))t3=1;
		else t3=0;
	}else t3=0;
	cout<<t3;
	if(t3){
		if(rs=='B'||xs=='B'||rs=='F'||xs=='F')t4=1;
		else t4=0;
	}else t4=0;
	cout<<t4;
	fclose(stdin);
	fclose(stdout);
	//ys uid:230118859
	return 0;
} 
