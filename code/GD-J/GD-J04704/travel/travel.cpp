#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else cout<<0;
	int a1,a2;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		for(char i='A';i<='C';i++){
			if(s1[2]==i) a1=1;
			if(s2[2]==i) a2=1;
		}
		for(char i='D';i<='F';i++){
			if(s1[2]==i) a1=2;
			if(s2[2]==i) a2=2;
		}
		if(a1==a2) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&a1==a2){
		for(char i='A';i<'F';i++){
			if((s1[2]==i&&s2[2]==i+1)||(s1[2]==i+1&&s2[2]==i)){
				cout<<1;
				return 0;
			}
		}
		cout<<0;
	}
	else cout<<0;
	return 0;
} 
