#include<iostream>
using namespace std;
//模拟即可 
int r,x;//r，x的车厢 
string rs,xs;//r，x的座位号
int vis; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>r>>rs>>x>>xs;
	if(r==x)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	
	if(rs[0]==xs[0]&&rs[1]==xs[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	
	if(((rs[2]>='A'&&rs[2]<='C')&&(xs[2]>='A'&&xs[2]<='C'))||((rs[2]>='D'&&rs[2]<='F')&&(xs[2]>='D'&&xs[2]<='F'))){
	cout<<"1";	
	if(((rs[2]>='A'&&rs[2]<='C')&&(xs[2]>='A'&&xs[2]<='C')))vis=1;
	else vis=2;
	}else{
		cout<<"00";
		return 0;
	 }
	 
	if(vis==1){
		if((rs[2]>='A'&&rs[2]<='B')&&(rs[2]>='A'&&rs[2]<='B')&&rs[2]!=xs[2]){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
		if((rs[2]=='C'&&xs[2]=='B')||(xs[2]=='C'&&rs[2])=='B'){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}else if(vis==2){
			if((rs[2]>='D'&&rs[2]<='F')&&(rs[2]>='D'&&rs[2]<='F')&&rs[2]!=xs[2]){
			cout<<"1";	
			return 0;
			}else {
				cout<<"0";
				return 0;
				}
	}
	return 0;
}
