#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(s1.substr(0,2)!=s2.substr(0,2)){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	int x=int(s1[2]-'A')+1;
	int y=int(s2[2]-'A')+1;
	if( ( ( x==1 || x==2 || x==3 ) && ( y==1 || y==2 || y==3 ) ) || ( ( x==4 || x==6 ) && ( y==4 || y==6 ) ) ){
		cout<<"1";
		if(abs(x-y)==1||(x==4)||(y==4)){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"00";
	}
	return 0;
} 
