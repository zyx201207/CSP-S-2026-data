#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
		if(s2.substr(0,2)!=s4.substr(0,2)){
			cout<<"000";
			return 0;
		}
		else{
			cout<<1;
			if(s2[2]<='C'&&s2[2]>='D'){
				cout<<"00";
				return 0;
			}
			else{
				cout<<1;
				if(abs(int(s2[2]-s4[2]))!=1&&s2[2]<='C'){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
		}
	}
	return 0;
}
