#include<bits/stdc++.h> 
using namespace std;
int turn(char u){
	int a=0,b,num=int(u);
	string n;
	char s;
	while(num=1){
		n+=num%2*10^a;
		num/2;
		a++;
	}
	for(int i=a-1;i>=0;i--){
		s=n[i];
	}
	return int(s);
}
int and1(int a,int b){
	string str1,str2,str3;
	str1=a,str2=b;
	for(int i=0;i<max(str1.size(),str2.size());i++){
		if(str1[i]==str2[i]&&str2[i]==1) str3[i]=1;
	}
}
int main(){
	int ci=0;
	char s[2*10^5],temp;
	ifstream inf("and.in");
	ofstream outf("and.out");
	while(inf>>temp){
		if(temp!=' ' ){
			s[ci]=temp;
			ci++;
		}
	}
	int str[ci],a=0;
	for(int i=0;i<ci;i++){
		str[i]=turn(s[i]);
	}
	for(int i=0;i<(ci+1)/2*ci;i++){
		for(int j=i+1;j<(ci+1)/2*ci;j++){
			if(and1(str[i],str[j])>a){
				a=and1(str[i],str[j]);
			}
		}
	}
	outf<<a;
	return 0;
}
