#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4,s="";
	cin>>c1>>c2>>c3>>c4;
	int trr=0,trx=0,sr=0,sx=0;
	char wr,wx;
	trr=(c1[0]-'0')*10+c1[1]-'0';
	trx=(c3[0]-'0')*10+c3[1]-'0';
	sr=(c2[0]-'0')*10+c2[1]-'0';
	sx=(c4[0]-'0')*10+c4[1]-'0';
	wr=c2[2];
	wx=c4[2];
	//cout<<trr<<" "<<trx<<" "<<sr<<" "<<sx<<" "<<wr<<" "<<wx;
	if(trr==trx){
		cout<<1;
		if(sr==sx){
			cout<<1;
			if((wr>='A'&&wx>='A'&&wr<='C'&&wx<='C')||(wr>='D'&&wx>='D'&&wr<='F'&&wx<='F')){
				cout<<1;
				if(sr==sx&&(wr+1==wx||wr-1==wx)){
					cout<<1;
				}else if(wr==wx&&(sr+1==sx||sr-1==sx)){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
} 
