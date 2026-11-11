#include<iostream>
#include<cstring>

using namespace std;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ra,xa;
	string rb,xb;
	cin>>ra;//³µÏá
	cin>>rb;
	cin>>xa;
	cin>>xb;
	int rc,xc;
	char rd,xd;
	rd = rb[2];
	xd = xb[2];//×ÖÄ¸
	int r1,r2,x1,x2,r3,x3;
	r1 = rb[0] - '0';
	r2 = rb[1] - '0';
	x1 = xb[0] - '0';
	x2 = xb[1] - '0';
	r3 = r1*10 + r2;
	x3 = x1*10 + x2;//ÐòºÅ
	if(ra==xa){
		cout<<1;
		if(r3==x3){
			cout<<1;
			if(rd=='A'&&(xd=='B'||xd=='C')){
				cout<<1;
				if(rd+1==xd||rd-1==xd){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(rd=='B'&&(rd=='A'||rd=='C')){
				cout<<1;
				if(rd+1==xd||rd-1==xd){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(rd=='C'&&(xd=='B'||xd=='A')){
				cout<<1;
				if(rd+1==xd||rd-1==xd){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if((rd=='D'&&xd=='F')||(rd=='F'&&xd=='D')){
				cout<<11;
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
	return 0;
}
