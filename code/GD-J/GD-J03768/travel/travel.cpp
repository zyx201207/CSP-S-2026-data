#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[10],c2[10],c3[10],c4[10];
	cin>>c1>>c2>>c3>>c4;
	if((c1[0]==c3[0])&&(c1[1]==c3[1])){
		if((c2[0]==c4[0])&&(c2[1]==c4[1])){
			if((('A'<=c2[2]&&c2[2]<='C')&&('A'<=c4[2]&&c4[2]<='C'))||(((c2[2]=='D')&&(c4[2]=='F'))||((c2[2]=='F')&&(c4[2]=='D')))){
				if((c2[2]==c4[2]+1)||(c2[2]==c4[2]-1)){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

