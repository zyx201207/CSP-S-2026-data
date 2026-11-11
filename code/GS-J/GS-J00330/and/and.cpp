#include <iostream>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int c1,c2,s1,s2,a,b;
	char s3,s4;
	cin>>c1>>s1>>s3>>c2>>s2>>s4;
	if(s3=='A'){
		b=1;
	}
	if(s3=='B'){
		b=2;
	}
	if(s3=='C'){
		b=3;
	}
	if(s3=='D'){
		b=4;
	}
	if(s4=='F'){
		b=5;
	}
	if(s4=='A'){
		a=1;
	}
	if(s4=='B'){
		a=2;
	}
	if(s4=='C'){
		a=3;
	}
	if(s4=='D'){
		a=4;
	}
	if(s4=='F'){
		a=5;
	}
	if(c1==c2){
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			if(a<=3&&b<=3){
				cout<<"1";
				if(a-b==1){
					cout<<"1";
				}
				else if(b-a==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(a+b==9){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
