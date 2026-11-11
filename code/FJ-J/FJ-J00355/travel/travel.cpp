#include <bits/stdc++.h>
using namespace std;
char rh[5],xh[5],r[5],x[5];
bool b=0,f=0,d=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>rh>>x>>xh;
	//是否在同一节车厢
	if(r[0]==x[0]){
		if(r[1]==x[1]){
			cout<<"1";
		}
		else if(f!=1&&r[1]!=x[1]){
			cout<<"0";
			f=1;
		}
	}
	else{
		cout<<"0";
		f=1;
	}
	if(f==1){
		cout<<"000";
		return 0;
	}
	//是否在同一节车厢的同一排
	if(f==0){
		if(rh[0]==xh[0]){
			if(rh[1]==xh[1]){
				cout<<"1";
			}
			else if(b!=1&&rh[1]!=xh[1]){
				cout<<"0";
				b=1;
			}
		}
		else{
			cout<<"0";
			b=1;
		}
	}
	else{
		cout<<"0";
		b=1;	
	}
	if(b==1){
		cout<<"00";
		return 0;
	}
	//位于过道的同一侧
	if(b==0){
		if(((rh[2]>='A'&&rh[2]<='C'&&xh[2]>='D'&&xh[2]<='F')||(xh[2]>='A'&&xh[2]<='C'&&rh[2]>='D'&&rh[2]<='F'))&&b!=1&&f!=1){
			cout<<"0";
			d=1;
		} 
		else{
			cout<<"1";
		}
	}
	else{
		cout<<"0";
		d=1;
	}
	if(d==1){
		cout<<"0";
		return 0;
	}
	//是否相邻
	if(d==0){
		if((rh[2]-xh[2]==1||xh[2]-rh[2]==1)&&d!=1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
	return 0;
}
