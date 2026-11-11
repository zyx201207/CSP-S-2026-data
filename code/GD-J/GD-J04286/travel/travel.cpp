#include<bits/stdc++.h>
using ll=long long;
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	fclose(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				if(s1[2]=='A'&&s2[2]>='C'){
					cout<<"1110\n";
				}
				else{
					cout<<"1111\n";
				}
			}
			else{
				cout<<"1100\n";
			}
		}
		else{
			cout<<"1000\n";
		}
	}
	else{
		cout<<"0000\n";
	}
	return 0;
} 
