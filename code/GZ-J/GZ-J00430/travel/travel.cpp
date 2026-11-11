//GZ-J00430 贵阳市第一实验中学 晏锦桐
#include<bits/stdc++.h>
using namespace std;
string cr,sr;
string cx,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx){
		cout<<"0000";
		return 0;
	}
	else if(sr[0]!=sx[0]||sr[1]!=sx[1]){
		cout<<"1000";
		return 0;
	}
	else if(sr[2]=='D'||sx[2]=='D'){
		if(sr[2]=='F'||sx[2]=='F'){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1100";
		}	
	}
	else if(abs(sr[2]-sx[2])==1){
		cout<<"1111";
		return 0;
	}else{
		cout<<"1110";
		return 0;
	}
	return 0;
} 
