#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[4];
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	if(a[0]!=a[2]){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(a[1][i]!=a[3][i]){
			cout<<"1000";
			return 0;
		}
	}
	if(a[1][2]-'A'>=3&&a[3][2]-'A'<3){
		cout<<"1100";
		return 0;
	}
	if(a[1][2]-'A'<3&&a[3][2]-'A'>=3){
		cout<<"1100";
		return 0;
	}
	if(a[1][2]-a[3][2]==1||a[3][2]-a[1][2]==1)
	     cout<<"1111";
	else
	  cout<<"1110";     
	return 0;
}
