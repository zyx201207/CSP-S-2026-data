#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(s1[2]<='C'&&s2[2]<='C'){
				cout<<"1";
				int x=s1[2]-s2[2];
				if(abs(x)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if(s1[2]>='D'&&s2[2]>='D'){
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
