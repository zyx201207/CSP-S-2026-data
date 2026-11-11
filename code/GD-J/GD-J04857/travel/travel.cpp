#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1;
	string c2,s2;
	cin>>c1>>c2;
	cin>>s1>>s2;
	if(c1==s1){
		cout<<1;
		if((c2[0]==s2[0])&&(c2[1]==s2[1])){
			cout<<1;
			if((c2[2]<='C'&&s2[2]<='C')||(c2[2]>'C'&&s2[2]>'C')){
				cout<<1;
				if((c2[2]==s2[2]+1)||(c2[2]==s2[2]-1)) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
