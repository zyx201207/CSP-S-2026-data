#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("trave.in","r",stdin);
	freopen("trave.out","w",stdout);
	bool c;
	string ag,bg,az,bz;
	cin>>ag>>az>>bg>>bz;
	if(ag[0]==bg[0]&&ag[1]==bg[1]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(az[0]==bz[0]&&az[1]==bz[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(65<=az[2]&&67>=az[2]){
		c=1;
	}else{
		c=0;
	}
	if(65<=bz[2]&&67>=bz[2]){
		if(c){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(!c){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(az[2]-bz[2]==1||az[2]-bz[2]==-1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
