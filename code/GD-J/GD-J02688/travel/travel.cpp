#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1[1],a2[2],a3[1],a4[2];
	string c1,c2,c3,c4;
	cin >>c1 >>c2 >>c3 >>c4;
	a1[0]=c1[0]-'0';
	a1[1]=c1[1]-'0';
	a2[0]=c2[0]-'0';
	a2[1]=c2[1]-'0';
	a2[2]=c2[2]-'0';
	a3[0]=c3[0]-'0';
	a3[1]=c3[1]-'0';
	a4[0]=c4[0]-'0';
	a4[1]=c4[1]-'0';
	a4[2]=c4[2]-'0';
	if(a1[1]==a3[1] && a1[0]==a3[0]){
		cout <<1;
		if(a2[0]==a4[0] && a2[1]==a4[1]){
			cout <<1;
			if((a2[2]<=19 && a4[2]>19) || (a4[2]<=19 && a2[2]>19)){
				cout <<0;
				cout <<0;
			}else{
				if(a2[2] <=19 && a4[2]<=19){
					if(a2[2]>a4[2]){
						if(a2[2]-a4[2]==2){
							cout <<10;
						}
						if(a2[2]-a4[2]==1){
							cout <<11;
						}
					}else{
						if(a4[2]-a2[2]==2){
							cout <<10;
						}
						if(a4[2]-a2[2]==1){
							cout <<11;
						}
					}
				}
				if(a2[2]>19 && a4[2]>19){
					cout <<11;
				}
			}
			
		}else{
			cout <<0;
			cout <<0;
			cout <<0;
		}
	}else{
		cout <<0;
		cout <<0;
		cout <<0;
		cout <<0;
	}
	return 0;
} 
