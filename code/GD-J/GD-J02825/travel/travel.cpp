#include <bits/stdc++.h>
using namespace std;
int c1,c3;
string c2,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) cout<<"1";
	else{
		for(int i=1;i<=4;i++) cout<<"0";
		return 0;
	} 
	for(int i=0;i<2;i++){
		if(c2[i]!=c4[i]){
			for(int i=1;i<=3;i++) cout<<"0";
			return 0;
		}
	}
	cout<<"1";
	if(((c2[2]>='A'&&c2[2]<='C') && (c4[2]>='A'&&c4[2]<='C')) || ((c2[2]>='D'&&c2[2]<='F') && (c4[2]>='D'&&c4[2]<='F')) ) {
		cout<<"1";
	}
	else{
		for(int i=1;i<=2;i++) cout<<"0";
		return 0;	
	}
	if ((c2[2]-1==c4[2]) || (c2[2]+1==c4[2])) cout<<"1";
	else cout<<"0";
	return 0;
} 
