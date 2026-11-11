#include<bits/stdc++.h>
using namespace std;
int num1[5],num2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	int a=0,b=0;
	if(a1==b1){
		cout<<"1";
		a=(a2[0]-'0')*10+(a2[1]-'0');
		b=(b2[0]-'0')*10+(b2[1]-'0');
		if(a==b){
			cout<<"1";
			a=a2[2]-'A';
			b=b2[2]-'A';
			if((a<3&&b<3)||(a>=3&&b>=3)){
						cout<<"1";
						if((a-b==1||a-b==-1)){
							cout<<"1";
						}else{
							cout<<"0";
							return 0;
						}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
