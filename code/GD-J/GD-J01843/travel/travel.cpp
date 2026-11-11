#include<iostream>
using namespace std;

struct node{
	string train;
	string seat;
};

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	node a,b;
	cin >> a.train >> a.seat >> b.train >> b.seat;
	if(a.train!=b.train){
		cout << "0000";
		return 0;
	}
	int pa=(a.seat[0]+'0')*10+(a.seat[1]+'0');
	int pb=(b.seat[0]+'0')*10+(b.seat[1]+'0');
	if(pa!=pb){
		cout << "1000";
		return 0;
	}
	int sea=a.seat[2]-'A';
	int seb=b.seat[2]-'A';
	if(sea>seb)swap(sea,seb);
	if(sea==0&&(seb!=1&&seb!=2)){
		cout << "1100";
		return 0;
	}
	if(sea==1&&seb!=2){
		cout << "1100";
		return 0;
	}
	if(sea==2){
		cout << "1100";
		return 0;
	}
	if(sea==3&&seb!=5){
		cout << "1100";
		return 0;
	}
	if(sea==5){
		cout << "1100";
		return 0;
	}
	if(sea==0&&seb!=1){
		cout << "1110";
		return 0;
	}
	if(sea==1&&seb!=2){
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
} 
