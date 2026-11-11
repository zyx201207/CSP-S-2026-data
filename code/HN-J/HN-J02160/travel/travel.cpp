#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("travel.in","r",stdin);
//freopen("travel.in","r",stdin);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	char l[10]={'A','B','C'};
	char l2[10]={'D','F'};
	bool x1=0;
	for(int i=0;i<c1.size();i++){
		if(c1[i]==c3[i]){
			x1=1;
		}else{
			x1=0;
			break;
		}
	}
	if(x1==1) cout<<"1";
	else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	bool x2=0;
	for(int i=0;i<2;i++){
		if(c2[i]==c4[i]) x2=1;
		else{
			x2=0;
			break;
		}
	}
	if(x2==1) cout<<"1";
	else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	bool x3=0,x4=0;
	if(c2[c2.size()-1]=='A'||c2[c2.size()-1]=='B'||c2[c2.size()-1]=='C'){
			for(int j=0;j<3;j++){
				if(c4[c2.size()-1]==l[j]) x3=1;
			}
			if(c2[c2.size()-1]=='A'){
				if(c4[c2.size()-1]=='B') x4=1;
			}else if(c2[c2.size()-1]=='B'){
				if(c4[c2.size()-1]=='A'||c4[c2.size()-1]=='C') x4=1;
			}else if(c4[c2.size()-1]=='C'){
				if(c2[c2.size()-1]=='B') x4=1;
			}
		}else{
			for(int j=0;j<2;j++){
				if(c4[c2.size()-1]==l2[j]) x3=1;	
			}
			if(c2[c2.size()-1]=='D'){
				if(c4[c2.size()-1]=='F') x4=1;
			}else if(c2[c2.size()-1]=='F'){
				if(c4[c2.size()-1]=='D') x4=1;
			}
		}
	if(x3==1) cout<<"1";
	else cout<<"0";
	if(x1==x2&&x1==x3&&x1==x4) cout<<"1";
	else cout<<"0";
	return 0;
}
