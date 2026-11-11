#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ch=0,pa=0,ce=0,le=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w","stdout");
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ch=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		pa=1;
	}
	int r=s1[2]-'A'+1;
	int x=s2[2]-'A'+1;
	int ma=max(r,x);
	int mi=min(r,x);
	if(ma==2&&mi==1){
		ce=1;
		le=1;
	}
	if(ma==3&&mi==2){
		ce=1;
		le=1;
	}
	if(ma==3&&mi==1){
		ce=1;
	}
	if(ma==6&&mi==4){
		ce=1;
		le=1;
	}
	if(ma==4&&mi==3){
		ce=1;
	}
	if(ma==4&&mi==1){
		ce=1;
	}
	if(ma==6&&mi==1){
		ce=1;
	}
	if(ma==4&&mi==2){
		ce=1;
	}
	if(ma==6&&mi==2){
		ce=1;
	}
	if(ma==6&&mi==3){
		ce=1;
	}
	if(ch==1){
		cout<<"1";
		if(pa==1){
			cout<<"1";
			if(ce==1){
				cout<<"1";
				if(le==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000"<<" ";
	}
	return 0;
}
