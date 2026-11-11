#include<bits/stdc++.h> 
using namespace std;
int main(){
	string str,left,right,s;
	char temp,y;
	int cishu=0,n=0,large=0,num=0,kg=0,m=0,x;
	ifstream inf("string.in");
	ofstream outf("string.out");
	while(inf>>temp){
		if(cishu!=0&&kg%2==1){
			x+=(10^m)*int(temp);
		}else if(cishu!=0&&kg%2==0){
			y+=temp;
		}else if(temp==' '){
			if(kg%2==1){
				large+=x;
				for(int j=0;j<x;j++){
					str+=y;
				}
				x=0;
			}else{
				y={};
			}
			kg++;
		}
		cishu++;
	}
	if(large%2==1){
		large++;
	}
	right=str[str.size()];
	left=str[0];
	for(int i=0;i<large/2;i++){
		left=str[i];
		right=str[str.length()-i];
		if(left!=right){
			num++;
		}
	}
	outf<<num;
	return 0;
}
