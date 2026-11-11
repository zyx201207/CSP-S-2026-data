#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[15];
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	if(a[0]==a[5]&&a[1]==a[6]){
	cout<<"1";
	 if(a[2]==a[7]&&a[3]==a[8]){
	 	cout<<"1";
	 	if((a[4]<='C'&&a[9]<='C')||(a[4]>'C'&&a[9]>'C')){
	 		cout<<"1";
	 		if(a[4]-a[9]==1||a[4]-a[9]==-1){
	 			cout<<"1";
			 }else{cout<<"0";
			 }
		 }else{cout<<"00";
		 }
	 }else{
	 	cout<<"000";
	 }
	}else{
	cout<<"0000";
	}
	return 0;
}
