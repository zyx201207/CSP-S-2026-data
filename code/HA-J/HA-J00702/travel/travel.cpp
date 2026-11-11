#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		ll ok=1;
		for(ll i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				ok=0;
				break;
			}
		}
		if(ok==1){
			cout<<"1";
			ll ss1,ss2;
			if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
				ss1=1;
			}else{
				ss1=0;
			}
			if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
				ss1=1;
			}else{
				ss1=0;
			}
			if(ss1==ss2){
				cout<<"1";
				ll sq=s1[2]-'A'+1;
				ll sp=s2[2]-'A'+1;
				if(sq>sp){
					swap(sq,sp);
				}
				if(sq+1==sp){
					cout<<"1";
				}else{
					cout<<"0";
				}
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
