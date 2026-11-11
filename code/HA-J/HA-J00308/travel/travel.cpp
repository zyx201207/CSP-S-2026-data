#include <bits/stdc++.h>
using namespace std;
int main (){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r=0;
	int y=0;
	int g=0;
	int  a[8];
	int b[8];
	int c[8];
	int d[8];
	for(int i=0;i<=1;i++){
		cin>>a[i];
	}
	for(int i=0;i<=2;i++){
		cin>>b[i];
	}
	for(int i=0;i<=1;i++){
		cin>>c[i];
	}
	for(int i=0;i<=2;i++){
		cin>>d[i];
	}
	
	
	if(a[0]!=c[0]||a[1]!=c[1]){
		cout<<"0000";
}
	else{
		cout<<"1";
	
		if(b[0]!=d[0]||b[1]!=d[1]){
			cout<<"000";
}
		else{
			cout<<"1";
	
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
	
				g++;
	
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
	
				y++;
	}
			if(g==y){
				cout<<"1";
	}
				else{
					cout<<"00";
					
					if(b[2]=='b'||b[2]=='d'||d[2]=='d'||d[2]=='b'){
						cout<<"1";
					}
	}
}
}
}
	return 0;
 
}
