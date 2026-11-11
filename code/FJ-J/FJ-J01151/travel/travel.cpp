#include"bits/stdc++.h"
using namespace std;
string che1,wei1,che2,wei2;
string we1,we2;
bool que1,que2,que3,que4;
int main(){
	//100
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>che1>>wei1>>che2>>wei2;
	//1
	if(che1==che2){
		que1=1;
	}else{
		que1=0;
	}
	//2
	if(que1){
		
	for(int i=0;i<2;i++){
		we1+=wei1[i];
		we2+=wei2[i];
	}
	if(we1==we2){
		que2=1;
	}else{
		que2=0;
	}
	
	}else{
		que2=0;
	}
	//3
	if(que2){
		if( (wei1[2]<='C' && wei2[2]<='C') || (wei1[2]>='D' && wei2[2]>='D') ){
			que3=1;
		}else{
			que3=0;
		}
	}else{
		que3=0;
	}
	//4
	if(que3){
		if(wei1[2]>='D'){
			que4=1;
		}else if(wei1[2]<='C' && abs(wei1[2]-wei2[2])==1){
			que4=1;
		}else{
			que4=0;
		}
	}else{
		que4=0;
	}
	
	cout<<que1<<que2<<que3<<que4;
	return 0;
}
