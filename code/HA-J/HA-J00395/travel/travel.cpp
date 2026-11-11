#include<bits/stdc++.h>
using namespace std;
string c1,s2,c3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s2>>c3>>s4;
	if(c1==c3){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	int f=1;
	int ss1=(s2[0]-'0')*10+(s2[1]-'0');
	int ss2=(s4[0]-'0')*10+(s4[1]-'0');
	if(ss1==ss2){
		cout<<"1";
	}else{
		cout<<"0";
		f=0;
	}
	if(f==1){
		if(s2[2]<'D'&&s4[2]<'D'){
			cout<<"1";
		}else if(s2[2]>='D'&&s4[2]>='D'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
		
	int c=abs(ss1-ss2);
	int cc=abs(s2[2]-s4[2]);
	if((c==0 && cc<=1)||(c<=1 && cc==0)){
		if(s2[2]<'D'&&s4[2]<'D'){
			cout<<"1";
		}else if(s2[2]>='D'&&s4[2]>='D'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	return 0;
}
