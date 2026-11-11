#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
string s1,s2,s3,s4;

int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel5.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		if(s2[0]==s4[0] && s2[1]==s4[1]){
			cout<<1;
			if((s2[2]>'C' && s4[2]>'C') || (s2[2]<='C' && s4[2]<='C')){
				cout<<1;
				if(s2[2]-s4[2]==1 || s2[2]-s4[2]==-1){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
} 
