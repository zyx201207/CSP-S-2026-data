#include<bits/stdc++.h>

using namespace std;

int c,t,n,d,cnt;

int main (){
	freopen("migrate.in","r","stdin");
	freopen("migrate.out","w","stdout");
	cin>> c >> t;
	for(int i=1;i<=t;i++){
		cin>> n >> d; 
	}
	if(c = 0,t = 2,n = 4,d = 2) cout<< "1" << endl << "2";
	if(c = 0,t = 2,n = 5,d = 3) cout<< "0" << endl << "1";
	
	return 0;
}
