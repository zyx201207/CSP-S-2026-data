//GZ-J00627 ·¶Ώ£γρ 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(false);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<'1';
		if(a2[0]==b2[0] && a2[1]==b2[1]){
			cout<<'1';
			if((int(b2[2])%68 == int(b2[2])) && (int(a2[2])%68 == int(a2[2])) || ((int(b2[2])%68 != int(b2[2])) && (int(a2[2])%68 != int(a2[2])))){
				cout<<'1';
				if(abs(int(b2[2]) - int(a2[2]))==1){
					cout<<'1';
				}
				else{
					cout<<'0';
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	} 
	else{
		cout<<"0000";
		return 0;
	}
	
	return 0;
}
