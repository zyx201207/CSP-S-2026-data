#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b;
	char a2[3],b2[3];
	cin>>a;
	for(int i=0;i<3;i++) cin>>a2[i];
	cin>>b;
	for(int i=0;i<3;i++) cin>>b2[i];
	if(a==b){
		cout<<'1';
		if(a2[1]==b2[1] and a2[0]==b2[0]){
			cout<<'1';
			if(a2[2]-'A'<3 and b2[2]-'A'<3){
				cout<<'1';
				if(abs(a2[2]-b2[2])==1){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if(a2[2]-'A'>=3 and b2[2]-'A'>=3){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
