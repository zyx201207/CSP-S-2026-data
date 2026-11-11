#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		int row1 = 0,row2 = 0;
		row1 = s1[0]*10+s1[1];
		row2 = s2[0]*10+s2[1];
		if(row1 != row2){
			cout<<"000";
			return 0;
		}
		else{
			cout<<"1";
			//s1[3]
			if((((s1[2] == 'A') || (s1[2] == 'B') || (s1[2] == 'C')) && ((s2[2] == 'D') || (s2[2] == 'F'))) || (((s2[2] == 'A') || (s2[2] == 'B') || (s2[2] == 'C')) && ((s1[2] == 'D') || (s1[2] == 'F')))){
				cout<<"00";
				return 0;
			}
			else{
				cout<<"1";
				//cout<<endl<<"debug:"<<s1[2]<< " "<<s2[2];
				if((s1[2] == s2[2]+1) || (s2[2] == s1[2]+1)){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
		}
	}
	return 0;
}
