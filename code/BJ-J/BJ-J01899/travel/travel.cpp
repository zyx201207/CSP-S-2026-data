#include<bits/stdc++.h>
using namespace std;

struct travel{
	string car;
	string seat;
}a,b;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.car>>a.seat>>b.car>>b.seat;
	if(a.car==b.car){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	int t=a.seat.size(),t1;
	bool flag=0;
	for(int i=0;i<t;i++){
		if(a.seat[i]>='0'&&a.seat[i]<='9'&&b.seat[i]>='0'&&b.seat[i]<='9'){
			if(a.seat[i]==b.seat[i]){
				continue;
			}
			else{
				flag=1;
				cout<<"000";
				return 0;
			}
		}
		else{
			t1=i;
			break;
		}
	}
	if(!flag){
		cout<<'1';
		if(((a.seat[t1]=='A'||a.seat[t1]=='B'||a.seat[t1]=='C')&&(b.seat[t1]=='B'||b.seat[t1]=='A'||b.seat[t1]=='C'))||((a.seat[t1]=='F'||a.seat[t1]=='D')&&(b.seat[t1]=='D'||b.seat[t1]=='F'))){
			cout<<'1';
			
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	flag=0;
	for(int i=0;i<t;i++){
		if(a.seat[i]>='0'&&a.seat[i]<='9'&&b.seat[i]>='0'&&b.seat[i]<='9'){
			continue;
		}
		else{
			if((a.seat[i]=='A'&&b.seat[i]=='B')||(a.seat[i]=='B'&&b.seat[i]=='A')||(a.seat[i]=='B'&&b.seat[i]=='C')||(a.seat[i]=='C'&&b.seat[i]=='B')||(a.seat[i]=='D'&&b.seat[i]=='F')||(a.seat[i]=='F'&&b.seat[i]=='D')){
				 cout<<'1';
				 break;
			 }
			else{
				cout<<'0';
				break;
			}
		}
	}
	return 0;
}
