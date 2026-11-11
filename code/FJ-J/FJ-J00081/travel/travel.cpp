#include<bits/stdc++.h>
using namespace std;
char a[105];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=10;i++){
		cin>>a[i];
	}
	if(a[1]==a[6]&&a[2]==a[7]){
		cout<<1;
		if(a[3]==a[8]&&a[4]==a[9]){
			cout<<1;
			if((a[5]<='C'&&a[10]<='C')||(a[5]>='D'&&a[10]>='D')){
				cout<<1;
				if(abs(a[5]-a[10])==1) cout<<1;
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}
	else{
		cout<<"0000";
	} 
	return 0;
} 
