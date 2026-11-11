#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1;		//tong yi lie
	else{
		cout<<"0";
		cout<<'0';
		cout<<"0";
		cout<<'0';
		return 0;
	}
	for(int i=0;i<2;i++){   //tong yi pai
		if(s2[i]!=s4[i]){
			cout<<"0";
			cout<<'0';
			cout<<"0";
			return 0;
		}
	}
	cout<<1;
	if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){		//tong yi ce he xiang ling
		if(s4[2]=='A' || s4[2]=='B' || s4[2]=='C'){
				cout<<1;
				if(s2[2]=='B'){
					cout<<1;
					return 0;
				}
				else if((s2[2]=='A' && s4[2]=='B') || (s2[2]=='C' && s4[2]=='B')){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
					
		}
		else{
			cout<<"0";
			cout<<'0';
			return 0;
		}
	}
	else if(s2[2]=='D' || s2[2]=='F'){
		if(s4[2]=='D' || s4[2]=='F'){
			cout<<11;
			return 0;
		}
		else{
			cout<<"0";
			cout<<'0';
			return 0;
		}
	}
	return 0;
}
