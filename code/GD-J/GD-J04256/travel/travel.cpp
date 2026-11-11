#include<iostream>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char exp[13]={};
	for(int i=0;i<13;i++){
		exp[i]=getchar();
	}
	int c1=(exp[0]-'0')*10+exp[1]-'0',c2=(exp[7]-'0')*10+exp[8]-'0';
	int l1=(exp[3]-'0')*10+exp[4]-'0',l2=(exp[10]-'0')*10+exp[11]-'0';
	int s1=exp[5]-'A',s2=exp[12]-'A';
	if(c1==c2){
		if(l1==l2){
			if(s1<s2) swap(s1,s2);
			if(s1-s2==1){
				if(s1!=3){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
