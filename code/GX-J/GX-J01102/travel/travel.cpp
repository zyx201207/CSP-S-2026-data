#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r");
	//freopen("travel.out","w");
	string rc,rz,xc,xz;
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc){
		cout<<'1';
		if(rz[0]==xz[0] and rz[1]==xz[1])
		{
			cout<<'1';		
			if(rz[2] == "A" or rz[2] == "B" or rz[2] == "C" and xz[2] == "A" or xz[2] == "B" or xz[2] == "C" or rz[2] == "A" or rz[2] == "B" or rz[2] == "C" and xz[2] == "A" or xz[2] == "B" or xz[2] == "C")
			{
				cout<<'1';
				if(rz[2]+1 == xz[2] or rz[2]+1 == xz[2] or rz[2]-1 == xz or rz[2]-1 == xz)
				{
					cout<<'1';
				}
				else{
					cout<<'0';}
			}
			else if(rz[2] == "D" or rz[2]=="F" and xz[2] == "D" or xz[2] == "F"){
				cout<<'1';
				if(rz[2]+1 == xz[2] or rz[2]+1 == xz[2] or rz[2]-1 == xz or rz[2]-1 == xz)
				{
					cout<<'1';
				}
				else{
					cout<<'0';}
			}
			else{
				cout<<"00";}}
		else{
			cout<<"000";}
		}
	else{
		cout<<"0000";
		}
	
	return 0;}
