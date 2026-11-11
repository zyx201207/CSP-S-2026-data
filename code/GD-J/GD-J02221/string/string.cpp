#include <bits/stdc++.h>
using namespace std;
bool cheek(string strk){
	string stra="",strb="";
	for(char i:strk){
		stra=stra+i;
		strb=i+strb;
	}
	if(stra==strb){
		return true;
	}else{
		return false;
	}
}
int  main(){
 	freopen("string.in","r",stdin);
  	freopen("string.out","w",stdout);
long long n,ai,len=0;
	char si;
	string str_="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ai>>si;
		len+=ai;
		for(int j=1;j<=ai;j++){
			str_=str_+si;
		}
	}
	if(cheek(str_)){
		cout<<0;
		return 0;
	}
	long long sum=0;
	for(int i=0;i<len/2;i++){
		if(str_[i]!=str_[len-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
