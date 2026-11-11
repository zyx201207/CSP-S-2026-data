#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2, t1,t2;
	cin>>c1>>t1;s
	cin>>c2>>t2;
	char z1=t1[2];
	char z2=t2[2];
	if(c1==c2){//如果在同一车厢 
		cout<<"1";
		if(t1[0]==t2[0]&&t1[1]==t2[1]){//如果在同一排 
			cout<<"1";
			if((z1=='F'&&z2=='D')||(z1=='D'&&z2=='F')){//如果座位在D和F 
				cout<<"11";
			}else if((z1=='A'&&z2=='B')||(z1=='B'&&z2=='A')||(z1=='A'&&z2=='C')||(z1=='C'&&z2=='A')||(z1=='B'&&z2=='C')||(z1=='C'&&z2=='B')){//是不是在ABC 
				cout<<"1";
				if((z1=='A'&&z2=='B')||(z1=='B'&&z2=='A')||(z1=='B'&&z2=='C')||(z1=='C'&&z2=='B')){//是不是在ABC，且相邻 
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
			cout<<"00";
			}
		}else{//如果不在同一排 
			cout<<"000";
		}
	}else{//如果不在同一车厢 
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

