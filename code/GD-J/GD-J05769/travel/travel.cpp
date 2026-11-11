#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string xx1,xx2,yy1,yy2;
	cin>>xx1>>xx2>>yy1>>yy2;
	bool mxx=0;
	if(xx1!=yy1)
		mxx=1;
	if(mxx==1)
		cout<<"0";
	else
		cout<<"1";
	if(xx2[0]!=yy2[0]||xx2[1]!=yy2[1])
		mxx=1;
	if(mxx==1)
		cout<<"0";
	else
		cout<<"1";
	if(!((xx2[2]=='D'||xx2[2]=='F')&&(yy2[2]=='D'||yy2[2]=='F'))&&!((xx2[2]=='A'||xx2[2]=='B'||xx2[2]=='C')&&(yy2[2]=='A'||yy2[2]=='B'||yy2[2]=='C')))
		mxx=1;
	if(mxx==1)
		cout<<"0";
	else
		cout<<"1";
	if(!((xx2[2]=='D'||xx2[2]=='F')&&(yy2[2]=='D'||yy2[2]=='F'))&&!((xx2[2]=='A'||xx2[2]=='B')&&(yy2[2]=='A'||yy2[2]=='B'))&&!((xx2[2]=='B'||xx2[2]=='C')&&(yy2[2]=='B'||yy2[2]=='C')))
		mxx=1;
	if(mxx==1)
		cout<<"0";
	else
		cout<<"1";
} 
