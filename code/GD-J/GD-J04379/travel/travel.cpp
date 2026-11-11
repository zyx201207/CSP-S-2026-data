#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		string a,b;
		int x=0,y=0;
		a=s1.substr(0,2);
		b=s2.substr(0,2);
		if(a==b){
			if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
				x=1;
			}else{
				x=2;
			}
			if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
				y=1;
			}else{
				y=2;
			}
			if(x==y){
				if((x==2 && y==2) || (s2[2]=='A' & s1[2]=='B') || (s1[2]=='A' & s2[2]=='B') || (s2[2]=='B' & s1[2]=='C') || (s1[2]=='B' & s2[2]=='C')){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
