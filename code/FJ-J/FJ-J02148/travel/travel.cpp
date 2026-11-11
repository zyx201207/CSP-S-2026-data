#include<bits/stdc++.h>
using namespace std;
bool flag;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		for(int i=0;i<=1;i++){
			if(s1[i]!=s2[i]){
				flag=true;
				cout<<"000";
			}
		}
		if(flag==false){
			cout<<'1';
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					cout<<'1';
					if(abs(int(s1[2])-int(s2[2]))==1){
						cout<<'1';
						return 0;
					}
					else{
						cout<<'0';
						return 0;
					}
				}
				else{
					cout<<"00";
					return 0;
				}
			}
			else{
				if(s2[2]=='D'||s2[2]=='E'){
					cout<<'1';
					if(abs(int(s1[2])-int(s2[2]))==1){
						cout<<'1';
						return 0;
					}
					else{
						cout<<'0';
						return 0;
					}
				}
				else{
					cout<<"00";
					return 0;
				}
			}
		}
		else{
			return 0;
		}
		return 0;
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
