#include <bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(s_1<s_2) swap(s_1,s_2);
	if(c_1==c_2){
		cout<<1;
		if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]){
			cout<<1;
			if(((s_1[2]=='D'||s_1[2]=='F')&&s_2[2]>'C')||(s_1[2]<='C'&&(s_2[2]!='D'||s_2[2]!='F'))){
				cout<<1;
				if(s_1[2]-s_2[2]==1){
					cout<<1;
				}
				else cout<<0;
			}
			else{
				for(int i=1;i<=2;i++) cout<<0;
			}
		}
		else{
			for(int i=1;i<=3;i++) cout<<0;
		}
	} 
	else{
		for(int i=1;i<=4;i++) cout<<0;
	}
	return 0;
}
