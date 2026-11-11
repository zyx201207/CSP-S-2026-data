#include<bits/stdc++.h>
using namespace std;
string c1 , s1 , c2 , s2;
bool ca(char a , char b){
	if((a<='C'&&b>='D') || (b<='C'&&a>='D')) return false;
	return true;
}
bool lin(char a , char b){
	if( (int(a-1)==int(b)) || (int(a)==int(b-1)) ) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(ca(s1[2] , s2[2])){
				cout<<1;
				if(lin(s1[2] , s2[2])){
					cout<<1;
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";

	
	return 0;
}
//Trick||Treat!
