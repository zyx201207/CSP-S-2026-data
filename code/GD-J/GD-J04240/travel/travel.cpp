#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string w,r;
	string q,e;
	cin>>q>>w>>e>>r;
	if(q==e){
		if(w[1]==r[1]&&w[0]==r[0]){
			if((w[2]=='A'||w[2]=='B'||w[2]=='C')&&(r[2]=='A'||r[2]=='B'||r[2]=='C')){
				if((w[2]=='D'||w[2]=='E')&&(r[2]=='E'||r[2]=='D')){
					cout<<"1111";
					return 0;
				}
				else{
					if((w[2]=='A'&&r[2]=='B')||(w[2]=='B'&&r[2]=='C')||(r[2]=='B'&&w[2]=='C')||(r[2]=='B'&&w[2]=='C')){
						cout<<"1111";
						return 0;

					}else{
						cout<<"1110";
						return 0;
					}
				}

			}
			else{
			cout<<"1100";
			return 0;
			}
		}else {
			cout<<"1000";
			return 0;
		}
	}else {
		cout<<"0000";
		return 0;
	}



	return 0;
}
