#include<bits/stdc++.h>
using namespace std;
int a[3];
string b[3];
int main(){   
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	for(int i=1;i<=2;i++){
		cin>>a[i];
		cin>>b[i];
	}
	if(a[1]==a[2]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[1][1]==b[2][1]){
		cout<<1; 
	}else{
		cout<<"000";
		return 0;
	}
    char c[3];
    c[1]=b[1][2];
    c[2]=b[2][2];
    cout<<c[1]<<" "<<c[2];
	//if(c[1]>'A'and c[1]<'c' and c[2]>'a'and c[2]<'C' ){
	//	cout<<"1";
	//}else if(c[1]>'D'and c[1]<'F' and c[2]>'D'and c[2]<'F'){
	//	cout<<"1";
	//}else{
	//	cout<<"00";
     //   return 0;
	}
	if(int(b[1][2])-int(b[2][2])==1 or int(b[2][2])-int(b[1][2])==1){
		cout<<1;
	}else{
		cout<<0;
	}

	
	return 0;
}

