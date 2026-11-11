#include<bits/stdc++.h>
using namespace std;
char x[6],r[6];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=5;i++){
		cin>>r[i];
	}
	for(int i=1;i<=5;i++){
		cin>>x[i];
	}
	if(r[1]==r[1] && r[2]==x[2]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(r[3]==r[3] && r[4]==x[4]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((r[5]<='C'&&x[5]<='C')||(r[5]>='D'&&x[5]>='D')){
		cout<<"1";
		if(r[5]==x[5]-1||r[5]==x[5]+1){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"00";
	}
	
	return 0;
}
