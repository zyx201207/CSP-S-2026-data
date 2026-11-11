#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ax,ay,bx,by;
	cin>>ax>>ay>>bx>>by;
	if(ax==bx){
		cout<<'1';
		string ca="  ",cb="  ";
		ca[0]=ay[0];ca[1]=ay[1];
		cb[0]=by[0];cb[1]=by[1];
		if(ca==cb){
			cout<<'1';
			int dd,ee;
			if(ay[2]=='D'||ay[2]=='F')dd=0;
			if(ay[2]=='A'||ay[2]=='B'||ay[2]=='C')dd=1;
			if(by[2]=='D'||by[2]=='F')ee=0;
			if(by[2]=='A'||by[2]=='B'||by[2]=='C')ee=1;
			if(dd==ee){
				cout<<'1';
				bool bo=0;
				if(ay[2]=='D'&&by[2]=='F') bo=1;
				if(by[2]=='D'&&ay[2]=='F') bo=1;
				if(abs(ay[2]-by[2])==1 || bo){
					cout<<'1'; 
				}
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
