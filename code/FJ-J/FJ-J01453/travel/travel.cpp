#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[4];
	for(int i=0;i<6;i++){
		cin>>a;
	}
	if(a[0]==a[3]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a[1]==a[4]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a[2]+1==a[5]||a[2]-1==a[5]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
