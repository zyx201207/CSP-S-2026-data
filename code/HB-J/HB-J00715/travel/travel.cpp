#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string a1,a2;
	int p1,p2;
	char d1,d2;
	cin>>c1>>a1>>c2>>a2;
	p1=(int)a1[0]*10+(int)a1[1];
	p2=(int)a2[0]*10+(int)a2[1];
	d1=a1[2];
	d2=a2[2];
	if(c1==c2){
		cout<<1;
		if(p1==p2){
			cout<<1;
			bool flag1=0,flag2=0;
			if(d1=='D'||d1=='E') flag1=1;
			if(d2=='D'||d2=='E') flag2=1;
			if((flag1&&flag2)||(!flag1&&!flag2)){
				cout<<1;
				if(abs((int)d1-(int)d2)==1){
					cout<<1;
				}
				else cout<<0;
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
