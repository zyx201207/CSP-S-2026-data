#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
char seat1[4]={' ','A','B','C'};
char seat2[3]={' ','D','E'};
int r,x,rr,xx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> r1 >> r2 >> x1 >> x2;
	if(r1==x1){
		cout << 1;
		if(r2[0]==x2[0]&&r2[1]==x2[1]){
			cout << 1;
			r=1,x=1,rr=0,xx=0;
			for(int i=1;i<=3;i++){
				if(r2[2]==seat1[i]){
					r=0;
					rr=i;
				}
				if(x2[2]==seat1[i]){
					x=0;
					xx=i;
				}
			}
			if(r==x){
				cout << 1;
				if((r&&x)||(rr+xx==3)||(rr+xx==5))cout << 1;
				else cout << 0;
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else cout << "0000";
	return 0;
}
