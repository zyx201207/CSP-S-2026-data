#include<bits/stdc++.h>
using namespace std;
int c1,r1;
char c2[20],r2[20];
bool a[4];
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>r1>>r2;
	/*
	if(c1==r1)cout<<"1";
	else cout<<"0";
	int i=0;
	if(!b){
		cout<<"0"
	}
	
	if(a)cout<<"1";
	else cout<<"0";
	
	if(!a){
		cout<<"0";
	}else
	{
		
		if(a)cout<<"1";
		else cout<<"0";
	}

	
	*/
	if(c1==r1)a[0]=true;
	else a[0]=false;
	if(a[0]){
		if(c2[0]==r2[0]){
			if(c2[1]==r2[1]){
				a[1]=true;
			}else a[1]=false;
		}else a[1]=false;
		if(a[1]){
				if(c2[2]=='D'){
			if(r2[2]=='F'){
				a[2]=true;
			}else a[2]=false;
			}else if(c2[2]=='F'){
				if(r2[2]=='D')a[2]=true;
				else a[2]=false;
			}	else{
				if(r2[2]!='D'&& r2[2]!='F'){
					a[2]=true;
				}else a[2]=false;
			}	
		}
		if(a[2]){
			if(c2[2]=='D'||c2[2]=='F'){
				a[3]=true;
			}else{
				if(c2[2]-r2[2]=='A'-'B'||c2[2]-r2[2]=='B'-'A' )a[3]=true;
				else a[3]=false;
			}
		}	
	}
	for(int i=0;i<4;i++){
		if(a[i])cout<<"1";
		else cout<<"0";
	}
	return 0;
}