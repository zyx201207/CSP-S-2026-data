#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	int c1=0;
	string s1;
	int c2=0;
	string s2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
		if(c1==c2){
			cout<<1;
			if(s1[1]==s2[1] && s1[2]==s2[2]){
			cout<<1;
			}
			else{
			cout<<0;
			}
			if(s2[3]-s1[3]=='1' or s1[3]-s2[3]=='1'){
				cout<<1;
			}
			else{
			cout<<0;
			}
			
		}
		else{
			cout<<0000;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
