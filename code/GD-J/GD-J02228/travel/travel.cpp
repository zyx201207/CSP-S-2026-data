#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(s1[1]==s2[1]){
		cout<<1;
		if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='E'&&s2[2]>='E'){
			cout<<1;
			if(abs(s1[2]-s2[2])==1){
				cout<<1;
			}
			else cout<<0;
		}
		else{
			cout<<0;
			cout<<0;
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
	}
	
	return 0;
}
