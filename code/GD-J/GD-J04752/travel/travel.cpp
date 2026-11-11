#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,s_1="ABC",s_2="DF";
	bool same=false;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((s1[0]==s2[0]&&s1[1]==s2[1])&&c1==c2){
		cout<<1;
		same=true;
	}
	else{
		cout<<0;
	}
	for(int i=0;i<5;i++){
		if(!same){
			cout<<0;
			break;
		}
		if(s1[2]==s_1[i]){
			for(int j=0;j<3;j++){
				if(s2[2]==s_1[j]){
					cout<<1;
					break;
				}
				if(s2[2]==s_2[j]){
					cout<<0;
					break;
				}
			}
		}
		if(s1[2]==s_2[i]){
			for(int j=0;j<3;j++){
				if(s2[2]==s_2[j]){
					cout<<1;
					break;
				}
				if(s2[2]==s_1[j]){
					cout<<0;
					break;
				}
			}
		}
	}
	if((s1[2]-s2[2]==1||s1[2]-s2[2]==-1)&&same){
		if((s1[2]=='C'&&s2[2]=='D')||!same){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	else{
		if(((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))&&same){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
