#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	char s12,s22;
	cin>>c1>>s1>>c2>>s2;
	s12=s1[2];
	s22=s2[2];
//	cout<<s12<<" "<<s22<<" ";
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<"1";
		if(s1[1]!=s2[1]||s1[0]!=s2[0]){
			cout<<"000";
		}else{
			cout<<"1";
			if((s12>='D'&&s22<='C')||(s12<='C'&&s22>='D')){
				cout<<"00";
			}else{
				cout<<"1";
				if((s12+1!=s22&&s22+1!=s12)||(s12=='C'&&s22=='D')||(s12=='D'&&s22=='C')){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}
		}
	}
}
