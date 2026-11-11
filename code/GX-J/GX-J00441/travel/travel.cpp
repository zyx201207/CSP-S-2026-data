#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string str1[3],str2[4],str3[3],str4[4];
    for(int i=0;i<2;i++){
		cin>>str1[i];
	}
	for(int j=0;j<3;j++){
		cin>>str2[j];
	}
	for(int l=0;l<2;l++){
		cin>>str3[l];
	}
	for(int k=0;k<3;k++){
		cin>>str4[k];
	}
		if((str1[0]==str3[0])&&(str1[1]==str3[1])){
			cout<<"1"<<" ";
		}
		else{
			cout<<"0"<<" ";
		}
		if((str2[0]==str4[0])&&(str2[1]==str4[1])){
			cout<<"1"<<" ";
		}
		if(str2[2]=='A'){
			if((str4[2]=='B')&&(str4[2]=='C')&&(str4[2]=='A')){
				cout<<"1"<<" ";
		else{
			cout<<"0"<<" ";
		if((str2[2]=='A')&&(str4[2]=='B')){
			cout<<"1"<<" ";
		}
	}
}
}

		return 0;
	}
			
