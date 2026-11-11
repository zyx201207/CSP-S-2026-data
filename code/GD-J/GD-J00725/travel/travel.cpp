#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	int c1, c2;
	string s1, s2;
	cin >>c1 >>s1 >>c2 >>s2;
	if(c1==c2){
		cout <<1;
		int x=s1[0]==s2[0];
		int y=s1[1]==s2[1];
		if(x==y){
			cout <<1;
			int a, b;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				a=1;
			}
			else{
				a=2;
			}
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				b=1;
			}
			else{
				b=2;
			}
			if(a==b){
				cout <<1;
				char w1, w2;
					w1=s1[2];
					w2=s2[2];
				if(a==1){
					
					if(w1=='A'&&w2=='B'||w1=='B'&&(w2=='A'||w2=='C')||w1=='C'&&w2=='B'){
						cout <<1;
					}
					else{
						cout <<0;
						return 0;
					}
				}
				else{
					if(w1=='D'&&w2=='E'||w1=='E'&&w2=='D'){
						cout <<1;
					}
					else{
					cout <<0;
					return 0;
					}
				}
			}
			else{
				cout <<"00";
				return 0;
			}
		}
		else{
			cout <<"000";
			return 0;
		}
	}
	else{
		cout <<0000;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
