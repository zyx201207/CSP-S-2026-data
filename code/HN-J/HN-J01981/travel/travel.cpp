#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	char c1[5],s1[5],c2[5],s2[5];
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(((int(s1[2])>=65&&int(s1[2])<=67)&&(int(s2[2])>=65&&int(s2[2])<=67))||((int(s1[2])>=68&&int(s1[2])<=69)&&(int(s2[2])>=68&&int(s2[2])<=69))){
				cout<<1;
				if(int(s1[2])-int(s2[2])==-1||int(s1[2])-int(s2[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
} 
