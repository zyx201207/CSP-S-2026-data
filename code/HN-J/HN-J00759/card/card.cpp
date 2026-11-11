#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	string num1,cnt1,num2,cnt2;
	cin>>num1>>cnt1>>num2>>cnt2;
	if(num1 != num2){
		cout<<0;
	}
	else{
		cout<<1;
	}
	if(cnt1[0] == cnt2[0] && cnt1[1] == cnt2[1] && num1 == num2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(((cnt1[2]<='C'  &&  cnt2[2]<='C') || (cnt1[2]>='D' && cnt2[2]>='D')) && (cnt1[0] == cnt2[0] && cnt1[1] == cnt2[1] && num1 == num2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	if(((cnt1[2]<='C'  &&  cnt2[2]<='C') || (cnt1[2]>='D' && cnt2[2]>='D')) && (cnt1[0] == cnt2[0] && cnt1[1] == cnt2[1] && num1 == num2) && (cnt1[2] == cnt2[2]-1 || cnt1[2] == cnt2[2]+1)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	
	return 0;
} 
