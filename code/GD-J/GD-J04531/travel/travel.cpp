#include<bits/stdc++.h>
#define int long long
using namespace std;
string rcar,rnum,xcar,xnum;
int rcnt=0,xcnt=0;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cin>>rcar>>rnum>>xcar>>xnum;
	if(rcar==xcar)cout<<1;
	else cout<<0;
	for(int i=0;i<2;i++){
		rcnt+=rnum[i];
	}
	for(int i=0;i<2;i++){
		xcnt+=xnum[i];
	}
	if(rcar==xcar&&rcnt==xcnt)cout<<1;
	else cout<<0;
	char R=rnum[2],X=xnum[2];
	if(rcar==xcar&&rcnt==xcnt&&(R=='A'&&X=='B'||R=='B'&&X=='A'|| R=='C'&&X=='B' || R=='B'&&X=='C' ||R=='A'&&X=='C' || R=='C'&&X=='A'|| R=='D'&&X=='F' || R=='F'&&X=='D'))cout<<1;
	else cout<<0;
	if(rcar==xcar&&rcnt==xcnt&&(R=='A'&&X=='B'||R=='B'&&X=='A'|| R=='C'&&X=='B' || R=='B'&&X=='C' || R=='D'&&X=='F' || R=='F'&&X=='D'))cout<<1;
	else cout<<0;
	return 0;
} 
