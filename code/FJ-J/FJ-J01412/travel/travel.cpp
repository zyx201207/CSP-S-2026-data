#include<bits/stdc++.h>
using namespace std;
int trainA,trainB,pairsA,pairsB;
char sitA[5],sitB[5];
bool tick[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>trainA>>sitA;
	cin>>trainB>>sitB;
	if(sitA[2]=='A')pairsA=1;
	else if(sitA[2]=='B')pairsA=2;
	else if(sitA[2]=='C')pairsA=3;
	else if(sitA[2]=='D')pairsA=4;
	else pairsA=5;
	if(sitB[2]=='A')pairsB=1;
	else if(sitB[2]=='B')pairsB=2;
	else if(sitB[2]=='C')pairsB=3;
	else if(sitB[2]=='D')pairsB=4;
	else pairsB=5;
	if(trainA==trainB){
		tick[1]=1;
		cout<<1;
	}
	else cout<<0;
	if(tick[1] && sitA[0]==sitB[0] && sitA[1]==sitB[1]){
		tick[2]=1;
		cout<<1;
	}
	else cout<<0;
	if(tick[2] && ( (pairsA<=3&&pairsB<=3) || (pairsA>=4&&pairsB>=4) ) ){
		tick[3]=1;
		cout<<1;
	}
	else cout<<0;
	if(!tick[3]||(pairsA==1&&pairsB==3)||(pairsA==3&&pairsB==1))cout<<0;
	else cout<<1;
	return 0;
}
