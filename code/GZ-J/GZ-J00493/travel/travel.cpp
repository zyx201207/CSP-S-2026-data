//GZ-J00493   ≥¬ È≈µ 
#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int r=0,x=0,r2,x2;
	cin>>r
	char r1[100],x1[100],r3,x3;
	cin>>r1
	cin>>x;
	cin>>x1;
	int a=0,a1=0,a2=0,a3=0;
	if(r==x){
        a=1;
	}
	if(r1[0]=='0'){
        r2=r1[1];
	}
	else{
        r2=r1[0]+(r1[1]*10);
	}
	if(x1[0]=='0'){
        x2=x1[1];
	}
	else{
        r2=r1[0]+(r1[1]*10);
	}
	r3=r1[2];
	x3=x1[2];
	if(r2==x2){
        a1=1;
	}
	if(r3!='D' and x3!='D' or r3!='F' and x3!='F'){
		a2=1;
	}
	else{
		a2=1;
	}
	if(r3+1==x3 or x3+1==r3){
		a3=1;
	}
	cout<<a<<a1<<a2<<a3;
	//fclose(stdin);
	//fclose(stdout);
}

