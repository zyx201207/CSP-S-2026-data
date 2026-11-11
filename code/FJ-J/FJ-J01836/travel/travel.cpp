#include<bits/stdc++.h>
using namespace std;
int p1,p2,q1,q2,r1,r2;
char a1[10],a2[10],b1[10],b2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	p1=(a1[0]-'0')*10+a1[1]-'0';
	p2=(a2[0]-'0')*10+a2[1]-'0';
	q1=(b1[0]-'0')*10+b1[1]-'0';
	q2=(b2[0]-'0')*10+b2[1]-'0';
	r1=b1[2]-'A';
	r2=b2[2]-'A';
	if(p1==p2){
		cout<<1;
		if(q1==q2){
			cout<<1;
			if(r1<=2 && r2<=2 || r1>=3 && r2>=3){
				cout<<1;
				if(r1<=2 && r2<=2 && abs(r1-r2)==1 || r1>=3 && r2>=3){
					cout<<1;
				}
				else{
					cout<<0;
				}
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