#include <bits/stdc++.h>
using namespace std;

//int 

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,c3,c4;
	cin >> c1 >>c2 >> c3 >> c4;
	if(c2[2]=='F') c2[2]='E';
	if(c4[2]=='F') c4[2]='E';
	
	if(c1==c3) cout << "1";
	else {
		for(int i=1;i<=4;i++)cout << "0";
		return 0;
	}
	
	
	if(c2[1]==c4[1]) cout << "1";else cout << "0"; 
	
	if((c2[1]==c4[1])&&((c2[2]<'D'&&c4[2]<'D')||(c2[2]>='D'&&c4[2]>='D')))//
	 cout << "1";
	else cout << "0"; 
	
	if(abs(c2[2]-c4[2])==1||abs(c2[1]-c4[1])==1)
		cout << "1";
	else cout << "0";  
	return 0;
} 
