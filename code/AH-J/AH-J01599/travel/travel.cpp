#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	bool f=false;
	for(int i=1;i<=4;i++){
		if(f==true){
			cout<<"0";
			continue;
		}
		if(i==1){
			if(a1==a2) cout<<"1";
			else{
				cout<<"0";
				f=true;
			}
		}
		if(i==2){
			if(b1[0]==b2[0]&&b1[1]==b2[1]) cout<<"1";
			else{
				cout<<"0";
				f=true;
			}
		}
		if(i==3){
			if(((b1[2]=='A'||b1[2]=='B'||b1[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'))||((b1[2]=='D'||b1[2]=='F')&&(b2[2]=='D'||b2[2]=='F'))) cout<<"1";
			else{
				cout<<"0";
				f=true;
			}
		}
		if(i==4){
			if((b1[2]-'A'+1)<=3&&(b2[2]-'A'+1)<=3){
				if(((b1[2]-'A'+1)==(b2[2]-'A'))||((b1[2]-'A')==(b2[2]-'A'+1))) cout<<"1";
				else{
					cout<<"0";
					f=true;
				}
			}
			else if((b1[2]-'A'+1)>3&&(b2[2]-'A'+1)>3) cout<<"1";
			else{
				cout<<"0";
				f=true;
			}
		}
	}
	cout<<endl;
	return 0;
}
