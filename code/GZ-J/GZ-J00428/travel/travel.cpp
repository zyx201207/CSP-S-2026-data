//侯欣言  GZ-J00428 兴义市弘毅中学
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2;
	string wei1,wei2;
	cin>>a1>>wei1>>a2>>wei2;
	int i=0;
	if(a1==a2){
		i++;
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(wei1[0]==wei2[0]&&wei1[1]==wei2[1]&&i==1){
		i++;
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(i==2&&(wei1[2]<='C'&&wei2[2]<='C')||(wei1[2]>='D'&&wei2[2]>='D')){
		cout<<"1";
		i++;
	}else{
		cout<<"0";
	}
	int sum1,sum2;
	if(i==3&&abs(wei1[2]-wei2[2])==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	return 0;
} 
