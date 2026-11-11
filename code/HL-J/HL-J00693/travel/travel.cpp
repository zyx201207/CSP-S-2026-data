#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int d,ab,ba;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(s1[2]<='C'&&s1[2]>='A'){
				if(s2[2]<='C'&&s2[2]>='A'){
					ab=s1[2];
					ba=s2[2];
					if(ab-ba==1||ba-ab==1){
						cout<<1111;
					}else{
						cout<<1110;
					}
				}else{
					cout<<1100;
				}
			}else if(s2[2]<='E'&&s2[2]>='D'){
				ab=s1[2];
				ba=s2[2];
				if(ab-ba==1||ba-ab==1){
					cout<<1111;
				}else{
					cout<<1110;
				}
			}else{
				cout<<1100;
			}
		}else{
			cout<<1000;
		}
	}else{
		cout<<"0000";
	}
	return 0;
}