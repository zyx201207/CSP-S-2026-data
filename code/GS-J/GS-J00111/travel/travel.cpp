#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	int l=4;
	if(c1==c3){
		cout<<"1";
		l--;
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			cout<<"1";
			l--;
			if(c2[2]<='C'&&c4[2]<='C'||c2[2]=='F'&&c4[2]<='D'||c2[2]=='D'&&c4[2]<='F'){
				cout<<"1";
				l--;
				if(c2[2]-c4[2]==1||c4[2]-c2[2]==1){	
					cout<<"1";
					l--;
				}
			}
		}
	}for(int i=1;i<=l;i++){
		cout<<"0";
		
	}
	return 0;
}
