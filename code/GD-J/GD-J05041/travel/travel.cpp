#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string box_r,box_x,s_r,s_x;
bool judge(string a){
	if(a[2]=='A' || a[2]=='B' || a[2]=='C'){
		return true;
	} 
	else return false;
}
int main(){
	cin>>box_r>>s_r>>box_x>>s_x;
	if(box_r==box_x){
		cout<<"1";
		if(s_r[0]==s_x[0] and s_r[1]==s_x[1]){
			cout<<"1";
			if(judge(s_r)==judge(s_x)){
				cout<<"1";
				if(s_r[2]-s_x[2]==1 || s_x[2]-s_r[2]==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	} 
	else{
		cout<<"0000";
	}
	return 0;
} 
