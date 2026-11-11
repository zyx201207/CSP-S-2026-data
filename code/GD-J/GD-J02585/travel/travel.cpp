#include<bits/stdc++.h>
using namespace std;
char car1[4],zw1[4],car2[4],zw2[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>car1>>zw1>>car2>>zw2;
	int cmp=1;
	for(int i=0;i<(int)strlen(car2);i++){
		if(car2[i]!=car1[i]){
			cmp=0;
		}
	}	
	if(cmp){
		int h1,h2;
		h1=(zw1[0]-'0')*10+(zw1[1]-'0');
		h2=(zw2[0]-'0')*10+(zw2[1]-'0');
		if(h1!=h2){
			cout<<"1000"<<endl;
		}else{
			char fw1=zw1[2],fw2=zw2[2];
			int pd1,pd2;
			if(fw1=='A'||fw1=='B'||fw1=='C'){
				pd1=1;
			}else{
				pd1=2;
			}
			if(fw2=='A'||fw2=='B'||fw2=='C'){
				pd2=1;
			}else{
				pd2=2;
			}
			if(pd2!=pd1){
				cout<<"1100"<<endl;
			}else{
				if(pd2==2){
					cout<<"1111"<<endl;
				}else{
					if(abs(fw1-fw2)==1){
						cout<<"1111"<<endl;
					}else{
						cout<<"1110"<<endl;
					}
				}
			}
		}
	}else{
		cout<<"0000"<<endl;
	}
	
	
	
	
	return 0;	
}
