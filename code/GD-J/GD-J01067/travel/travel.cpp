#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int o[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			o[s1[2]-'A']++;
			o[s2[2]-'A']++;
			if(o[0]+o[1]+o[2]==2||o[3]+o[4]==2){
				cout<<1;
				if(o[0]+o[1]==2||o[1]+o[2]==2||o[3]+o[4]==2){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
