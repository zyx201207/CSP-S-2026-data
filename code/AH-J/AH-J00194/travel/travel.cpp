#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			cout<<"000";
			return 0;
		}else{
			cout<<"1";
			char s12=s1[2],s22=s2[2];
			if(s12>s22){
				swap(s12,s22);
			}
			if((s12=='A'&&s22=='B')||(s12=='B'&&s22=='C')||(s12=='D'&&s22=='F')){
				cout<<"11";
			}else{
				if(s12=='A'&&s22=='C'){
					cout<<"10";
				}else{
					cout<<"00";
				}
			}
		}
	}
	return 0;
}
