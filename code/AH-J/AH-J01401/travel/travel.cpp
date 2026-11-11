#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >>c1 >>s1 >>c2 >>s2;
	if(c1==c2){
		cout <<1;
	}
	else{
		cout <<0 <<0 <<0 <<0;
		return 0;
	}
	int s1n=0,s2n=0;
	for(int i=0;i<2;i++){
		s1n+=(s1[i]-'0')+s1n*10;
		s2n+=(s2[i]-'0')+s2n*10;
	}
	if(s1n==s2n){
		cout<<1;
	} 
	else{
		cout <<0 <<0 <<0;
		return 0;
	}
	int s1c=s1[2]-'A',s2c=s2[2]-'A';
	if(s1c<=2&&s2c<=2){
		cout <<1;
	}
	else{
		if(s1c>2&&s2c>2){
			cout <<1;
		}
		else{
			cout <<0 <<0;
			return 0;
		}
	}
	int tmp=s1c-s2c;
	if(tmp==1||tmp==-1){
		cout <<1;
	}
	else{
		cout <<0;
	}
	return 0;
} 
