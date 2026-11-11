#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>e;
	if(a==c){
		if(b[0]+b[1]==e[0]+e[1]){
			if((b[2]<68&&e[2]<68)||(b[2]>=68&&e[2]>=68)){
				if((b[2]-e[2]==1)||(e[2]-b[2]==1)){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}

