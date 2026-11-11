#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r1,x1;
	char r2[3],x2[3];
	cin>>r1>>r2;
	cin>>x1>>x2;
	int a=r2[0]+r2[1],b=x2[0]+x2[1];
	bool i=0,j=0,k=0;
	if(r1==x1){
		cout<<1;
		i=1;
	}else{
		cout<<0;
	}if(a==b&&i==1){
		cout<<1;
		j=1;
	}else{
		cout<<0;
	}if((((r2[2]=='A'&&(x2[2]=='B'||x2[2]=='C'))||(r2[2]=='B'&&(x2[2]=='A'||x2[2]=='C'))||(r2[2]=='C'&&(x2[2]=='B'||x2[2]=='A')))||(r2[2]=='D'&&x2[2]=='F')||(r2[2]=='F'&&x2[2]=='D'))&&i==1&&j==1){
		cout<<1;
		k=1;
	}else{
		cout<<0;
	}if((r2[2]+1==x2[2]||r2[2]-1==x2[2])&&i==1&&j==1&&k==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
